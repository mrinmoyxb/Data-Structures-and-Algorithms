#include <iostream>
#include <thread>

void test(int x){
    std::cout<<"Hello from thread!"<<std::endl;
    std::cout<<"Argument passed in: "<<x<<std::endl;
}

int main(){
    std::thread myThread(&test, 100);
    myThread.join(); //* waits for the thread to complete it's execution

    std::cout<<"Hello from my main thread"<<std::endl;
    return 0;
}