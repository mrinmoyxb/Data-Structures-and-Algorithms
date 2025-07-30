#include <iostream>
#include <thread>

static int counter = 0;
std::mutex mtx;

//! std::lock_guard<std::mutex> lock(mtx)
void incrementUsingLockGuard(const std::string& name){
    for(int i=0; i<100; i++){
        std::lock_guard<std::mutex> lock(mtx);
        counter+=1;
    }
}

//! std::mutex
void incrementUsingMutex(const std::string& name){
    std::cout<<"entered: "<<name<<std::endl;
    for(int i=0; i<100; i++){
        mtx.lock();
        counter+=1;
        mtx.unlock();
    }
    std::cout<<"released: "<<name<<std::endl;
}

//! std::unique_lock<std::mutex> lock(mtx)
void incrementUsingUniqueLock(const std::string& name){
    std::unique_lock<std::mutex> lock(mtx);
    counter+=1;
    lock.unlock();
}

int main(){
    // std::thread t1(incrementUsingLockGuard, "A");
    // std::thread t2(incrementUsingLockGuard, "B");
    // t1.join();
    // t2.join();

    std::thread t1(incrementUsingMutex, "A");
    std::thread t2(incrementUsingMutex, "B");
    t1.join();
    t2.join();

    std::thread t1(incrementUsingUniqueLock, "A");
    std::thread t2(incrementUsingUniqueLock, "B");
    t1.join();
    t2.join();

    std::cout<<"Counter: "<<counter<<"\n";
    return 0;
}