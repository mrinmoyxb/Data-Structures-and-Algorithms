#include <iostream>
#include <vector>
#include <stack>

void q1(int n){
    if(n<1){
        return;
    }
    std::cout<<n<<" ";
    q1(n-1);
    std::cout<<"Returning from "<<n<<std::endl;
}

void q2(int start, int end){
    if(start>end){
        return;
    }
    std::cout<<start<<std::endl;
    q2(start+1, end);
}

void q3(int count, int n){
    std::cout<<"count: "<<count<<std::endl;
    if(count > n){
        return;
    }
    std::cout<<"hello"<<std::endl;
    q3(count+1,n);
}

void q4(int count, int n){
    if(count>5){
        return;
    }
    std::cout<<count<<std::endl;
    q4(count+1, n);
}

void q5(int n){
    if(n<1){
        return;
    }
    std::cout<<n<<std::endl;
    q5(n-1);
}

void q6(int end){
    if(end<1){
        return;
    }
    q6(end-1);
    std::cout<<end<<std::endl;
}

void q7(int start, int end){
    if(start>end){
        return;
    }
    q7(start+1, end);
    std::cout<<start<<" ";
}

int q8(int n){
    if(n<1){
        return 0;
    }

    return n + q8(n-1);
}

void q9(int n, int sum){
    if(n<1){
        std::cout<<sum<<std::endl;
        return;
    }

    q9(n-1, n+sum);
}

void q10(int arr[], int size){
    int start = 0;
    int end = size-1;

    while(start<=end){
        std::swap(arr[start++], arr[end--]);
    }

    std::cout<<"After swap: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
}

void q11(int arr[], int start, int end, int size){
    if(start>end){
        return;
    }

    std::swap(arr[start], arr[end]);
    q11(arr, start+1, end-1, size);
}

void q12(std::string str){
    int s = 0;
    int e = str.length()-1;
    while(s<=e){
        if(str[s]!=str[e]){
            std::cout<<"not palindrome"<<std::endl;
            return;
        }
        s++;
        e--;
    }
    std::cout<<"it's a palindrome"<<std::endl;
}

bool q13(std::string str, int start, int end){
    if(start>end){
        return true;
    }

    if(str[start]!=str[end]){
        std::cout<<"it's not a palindrome"<<std::endl;
        return false;
    }else{
        return q13(str, start+1, end-1);
    }
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    // std::cout<<"SUM: "<<q8(5);
    // int arr[5] = {12, 13, 14, 15, 16};
    // q11(arr, 0, 4, 5);
    // std::cout<<"After swap: "<<std::endl;
    // for(int i=0; i<5; i++){
    //     std::cout<<arr[i]<<" ";
    // }

    std::string s = "mom";
    std::cout<<q13(s, 0, s.length()-1)<<std::endl;
    std::cout<<"fib: "<<fibonacci(8);
}