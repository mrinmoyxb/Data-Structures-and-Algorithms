#include <iostream>

//! Template:
//* Helps us to write generic programs.
//* Function Template
//* Class Template
template<typename T>
T calcMean(std::vector<T> data){
    T sum = 0;
    for(T val: data){
        sum+=val;
    }
    return sum/data.size();
}


template<typename T>
T add(T a, T b){
    return a+b;
}

template<typename T>
T sub(T a, T b){
    return a-b;
}

template <class T>
class Calculator{
private:
    T num;
public:
    Calculator(): num(10){}

    T add(T a, T b){
        return a+b;
    }

    T sub(T a, T b){
        return a-b;
    }

    //* Function Declaration
    T multiply(T a, T b);
};

//* Function Definition
template <class T>
T Calculator<T>::multiply(T a, T b){
    return a*b;
}

int main(){
    std::cout<<"Sum of two numbers: "<<add(10, 20)<<std::endl;
    std::cout<<"Sum of two numbers: "<<add(12.0, 10.0)<<std::endl;
    std::cout<<"Difference between two numbers: "<<sub(24.0, 12.0)<<std::endl;
    std::cout<<"Difference between two numbers: "<<sub(10, 5)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Class Calculator: "<<std::endl;
    Calculator<int> calculator;
    std::cout<<"Sum of two nums: "<<calculator.add(10, 20)<<std::endl;
    std::cout<<"Difference of two nums: "<<calculator.sub(24.0, 12.0)<<std::endl;
    return 0;
}