#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;
bool finished = false;

void producer(){
    for(int i=0; i<5; i++){
        std::lock_guard<std::mutex> lock(mtx);
        q.push(i);
        std::cout<<"Produced: "<<i<<std::endl;
    }
    cv.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    {
        std::lock_guard<std::mutex> lock(mtx);
        finished = true;
    }
    cv.notify_all();
}

void consumer(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{return !q.empty() || finished;});
        
        while(!q.empty()){
            int val = q.front();
            q.pop();
            std::cout<<"Consumed: "<<val<<std::endl;
        }

        if(finished && q.empty()) break;
    }   
}

int main(){
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    
    return 0;
}
