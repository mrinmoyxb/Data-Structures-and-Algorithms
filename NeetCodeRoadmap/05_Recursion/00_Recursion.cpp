#include <iostream>
using namespace std;

void func(int x){
    if(x==0){
        return;
    }
    cout<<1<<endl;
    func(x-1);
}

void printName(int start, int end){
    if(start>end){
        return;
    }
    cout<<"Recursion"<<endl;
    printName(start+1, end);
}

void printLinear(int i, int n){
    if(i>n){
        return;
    }
    cout<<"i: "<<i<<endl;
    printLinear(i+1, n);
}

void printNto1(int n){
    if(n<1){
        return;
    }
    cout<<"i: "<<n<<endl;
    printNto1(n-1);
}

void backtracking(int n){
    if(n<1){
        return;
    }
    backtracking(n-1);
    cout<<n<<endl;
}

int funcOfPower(int n){
    if(n<1){
        return 1;
    }
    return 2*funcOfPower(n-1);
}

void reachHome(int source, int destination){
    cout<<"Source: "<<source<<", Destination: "<<destination<<endl;
    if(source==destination){
        cout<<"Reached"<<endl;
        return;
    }
    reachHome(source+=1, destination);
}

int main(){
    ///printName(1, 5);
    //printNto1(10);
    backtracking(3);
    int p = funcOfPower(5);
    cout<<p<<endl;
    reachHome(1, 10);
    return 0;
}

//! Concept
//* Think of base condition first
//* Think of only one case, we need to solve just one case, other cases will solve automatically
//* Then, Think how will i reach the base case
//* Design step1 and step2 clearly