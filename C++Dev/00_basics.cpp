#include <iostream>
using namespace std;

void displayDataTypes(){
    int num1 = 2147483647;
    int num2 = -2147483648;
    std::cout<<"Num1: "<<num1<<std::endl;
    std::cout<<"Num2: "<<num2<<std::endl;
    std::cout<<"Datatype of num1: "<<typeid(num1).name()<<std::endl;
    std::cout<<std::endl;

    float num3 = 3.14f;
    float num4 = 2.3455555f;
    double num5 = 3E-5;

    std::cout<<"Num3: "<<num3<<std::endl;
    std::cout<<"Num4: "<<num4<<std::endl;
    std::cout<<"Num5: "<<num5<<std::endl;
    std::cout<<"Datatype of num3: "<<typeid(num3).name()<<std::endl;
    std::cout<<"Datatype of num5: "<<typeid(num5).name()<<std::endl;

    char a = 'a';
    char A = 'A';
    char n = 105;
    std::cout<<"Character: "<<a<<std::endl;
    std::cout<<"Character: "<<A<<std::endl;
    std::cout<<"Int in char: "<<n<<std::endl;
    std::cout<<"ASCII value of the character 'a' : "<<int(a)<<std::endl;
    std::cout<<"ASCII value of the character 'A' : "<<int(A)<<std::endl;

    bool cond = false;
    std::cout<<"Condition: "<<cond<<std::endl;
}

void check1(){
    int num1, num2;
    std::cout<<"Enter a number1: ";
    cin>>num1;
    std::cout<<"Enter a number2: ";
    cin>>num2;
    if(num1>num2){
        std::cout<<num1<<" is greater"<<std::endl;
    }else{
        std::cout<<num2<<" is greater"<<std::endl;
    }
}

int main(){
    //displayDataTypes();
    //check1();
    for(int i=0; i<10; i++){
        std::cout<<i<<std::endl;
    }
    return 0;
}