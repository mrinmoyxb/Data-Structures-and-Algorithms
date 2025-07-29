//! Concurrency: The fact that two or more events or circumstances happening or existing at the same time
//! Multiple things can happen at once, the order matters and sometimes tasks have to wait on shared resources
//! Parallelism: Everything happens at once, instantenously 
//? 1. Typically we have one main, sequential thread of execution
//? 2. One CPU core executes code sequentially

//* Performance is the currency of computing 

//? 1. Thread is a lightweight process. It allows us to execute two control flows at the same time
//? 2. The main thread is where the program starts
//? 3. Each thread shares same code, data and files and kernel context
//? 4. Each thread has it's own thread id, registers and stack

#include <iostream>
#include <thread>
#include <vector>

void test(int x){
    std::cout<<"hello from thread"<<std::endl;
    std::cout<<"argument passed in "<<x<<std::endl;
}

void test1(int x){
    std::cout<<"hello from thread"<<std::endl;
    std::cout<<"argument passed in "<<x<<std::endl;
}

int main(){
    // std::thread myThread(&test, 100);
    // myThread.join();

    auto lambda=[](int x){
        std::cout<<"Hello from lambda thread"<<std::this_thread::get_id()<<std::endl;
        std::cout<<"Argument passed: "<<x<<std::endl;
    };

    // std::thread myThread(lambda, 100);
    // myThread.join();

    std::vector<std::thread> threads;
    for(int i=0; i<10; i++){
        threads.push_back(std::thread(lambda, i+1));
    }

    for(int i=0; i<10; i++){
        threads[i].join();
    }
    
    std::cout<<"hello from my main thread"<<std::this_thread::get_id()<<std::endl;
    return 0;
}
