#include <iostream>

void reverseString(std::string &str, int start, int end){
    if(start>end){
        return;
    }

    std::swap(str[start], str[end]);
    reverseString(str, start+1, end-1);
}

bool checkPalindrome(int *arr, int size){
    bool isPalindrome = true;
    int start = 0;
    int end = size-1;

    while(start<=end){
        if(arr[start++]!=arr[end--]){
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}

bool checkPalindromeUsingRecursion(int *arr, int start, int end){
    if(start>end){
        return true;
    }

    if(arr[start]!=arr[end]){
        return false;
    }
    else{
        return checkPalindromeUsingRecursion(arr, start+=1, end-=1);
    }
}

bool checkPalindromeString(std::string str, int start, int end){
    if(start>end){
        return true;
    }

    if(str[start]!=str[end]){
        return false;
    }else{
        return checkPalindromeString(str, start+1, end-1);
    }
}

int main(){
    std::string word = "Apple";
    std::cout<<"Word: "<<word<<std::endl;
    reverseString(word, 0, word.length()-1);
    std::cout<<"Reverse word: "<<word<<std::endl;

    int *arr = new int[5];
    std::cout<<"\nArray: "<<std::endl;
    for(int i=0; i<5; i++){
        int element;
        std::cout<<"Enter element: ";
        std::cin>>element;
        arr[i] = element;
    }

    std::cout<<"Check Palindrome: "<<checkPalindrome(arr, 5)<<std::endl;
    std::cout<<"Check Palindrome Using Recursion: "<<checkPalindromeUsingRecursion(arr, 0, 5-1)<<std::endl;
    
    std::string w = "mom";
    std::cout<<"Is the word a palindrome: "<<checkPalindromeString(w, 0, w.length()-1)<<std::endl;
    return 0;
}