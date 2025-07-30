#include <iostream>
#include <thread>

//! std::thread t(function_name, parameter)
//! t.join()
//! t.detach()

void sayHello1(const std::string& name){
    for(int i=0; i<10; i++){
        std::cout<<"i: "<<i<<" "<<name<<std::endl;
        if(i==5 || i==8){
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }else{
            continue;
        }
    }
    std::cout<<"Hello, "<<name<<" from thread!\n";
}

void sayHello2(const std::string& name){
    for(int i=0; i<10; i++){
        std::cout<<"i: "<<i<<" "<<name<<std::endl;
    }
    std::cout<<"Hello, "<<name<<" from thread!\n";
}

int main(){
    // std::thread t1(sayHello1, "A");
    // std::thread t2(sayHello1, "B");
    // t1.join();
    // t2.join();
    std::thread t1(sayHello2, "A");
    t1.detach();
    std::cout<<"Main ends\n"<<std::endl;
    return 0;
}