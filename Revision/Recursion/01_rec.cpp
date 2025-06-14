#include <iostream>
using namespace std;

void printNum(int num){
    if(num==0){
        return;
    }
    std::cout<<num<<" ";
    printNum(num-1);
}

void printNumInAsc(int num){
    if(num==0){
        return;
    }
    printNumInAsc(num-1);
    std::cout<<num<<" ";
}

int main(){
    printNum(10);
    std::cout<<"\n";
    printNumInAsc(10);
    return 0;
}