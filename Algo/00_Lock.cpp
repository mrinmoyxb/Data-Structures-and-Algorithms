#include <iostream>
using namespace std;

void lock(){

    bool lock = false;

    while(true){
        while(lock);
        lock = true;

        std::cout<<"Critical Section"<<std::endl;
        for(int i=0; i<5; i++){
            std::cout<<i<<std::endl;
        }

        lock = false;
    }
}

int main(){

    //lock();
    bool check = false;
    bool *target = &check;

    bool originalValue = *target;
    *target = true;
    cout<<originalValue<<endl;
    
    return 0;
}