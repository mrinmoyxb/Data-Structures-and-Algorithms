#include <iostream>

int factorial(int num){
    std::cout<<"Calling factorial of "<<num<<std::endl;
    if(num==1){
        std::cout<<"Base case reached: factorial "<<num<<std::endl;
        return 1;
    }

    int result = num*factorial(num-1);
    std::cout<<"Returning: "<<num<<" * factorial "<<num-1<<" : "<<result<<std::endl;
    return result;
}

int fibonacci(int num){
    if(num<=1){
        return num;
    }else{
        return fibonacci(num-1)+fibonacci(num-2);
    }
}

int sumOfDigitsRange(int num){
    if(num==1){
        return 1;
    }
    return num + sumOfDigitsRange(num-1);
}

int sumOfDigits(int num){
    if(num==0){
        return 0;
    }

    int r = num%10;
    return r+sumOfDigits(num/10);
}

int powerFunction(int num, int p){
    if(p==1){
        return num;
    }
    return num * powerFunction(num, p-1);
}

void reverseString(std::string &word, int start, int end){
    if(start>=end){
        return;
    }

    std::swap(word[start], word[end]);
    reverseString(word, start+1, end-1);
}

bool palindromeChecker(std::string& s, int left, int right){
    if(left>=right){
        return true;
    }

    if(s[left]!=s[right]){
        return false;
    }

    return palindromeChecker(s, left+1, right+1);
}

int main(){
    // std::cout<<factorial(3);
    // std::cout<<std::endl;
    // std::cout<<fibonacci(8)<<std::endl;
    // std::cout<<sumOfDigitsRange(5);
    // std::cout<<sumOfDigits(123045);
    // std::cout<<powerFunction(2, 3);

    // std::string word = "apple";
    // reverseString(word, 0, word.length()-1);
    // std::cout<<"reversed word: "<<word<<std::endl;

    std::string w = "mom";
    std::cout<<palindromeChecker(w, 0, w.length()-1);
    return 0;
}