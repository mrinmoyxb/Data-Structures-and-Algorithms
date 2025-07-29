#include <iostream>
#include <thread>
#include <vector>

int main(){

    auto lambda = [](int x){
        std::cout<<"Thread id: "<<std::this_thread::get_id()<<std::endl;
        std::cout<<"Accessing element: "<<x<<std::endl;
    };

    std::vector<std::jthread> jthreads;
    for(int i=0; i<10; i++){
        jthreads.push_back(std::jthread(lambda, i+1));
    }

    for(int i=0; i<10; i++){
        jthreads[i].join();
    }


    return 0;
}