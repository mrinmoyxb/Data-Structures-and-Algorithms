#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//! Formula: floor(M(kA mod 1))
void multiplicationHashFunction(int value, int sizeOfHashTable, double A){
    int h1 = floor(sizeOfHashTable * (fmod((value*A), 1)));
    cout<<"Hash Value: "<<h1<<endl;
}

int main(){
    multiplicationHashFunction(12345, 10, 0.01);
    return 0;
}