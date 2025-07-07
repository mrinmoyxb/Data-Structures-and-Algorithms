#include <iostream>
const double pi = 3.14159265359;

double degreeToRadian(double degree){
    double result = (pi/180)*degree;
    return result;
}

int main(){
    std::cout<<degreeToRadian(120)<<std::endl;
}