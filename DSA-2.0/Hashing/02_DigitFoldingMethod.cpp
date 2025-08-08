#include <iostream>
#include <string>

std::vector<std::string> splitString(const std::string& input){
    std::vector<std::string> result;
    int i=0;
    int len = input.length();

    while(i<len){
        if(i+1<len){
            result.push_back(input.substr(i, 2));
        }else{
            result.push_back(input.substr(i, 1));
        }
    }
    i+=2;
}

int main(){
    std::string s = "12345";
    splitString(s);
    std::cout<<s<<std::endl;
    return 0;
}