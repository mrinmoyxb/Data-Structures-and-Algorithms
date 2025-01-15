#include <iostream>
#include <vector>
#include <map>
using std::string;

auto sum(int n1, int n2){
    return n1+n2;
}

void displayMap(){
    std::map<int, int> m;
    m[1] = 100;
    m[2] = 200;
    m[3] = 300;

    for(const auto& pair: m){
        std::cout<<pair.first<<" "<<pair.second<<std::endl;
    }

    std::map<int, string> m1 = {{1, "A"}, {2, "B"}, {3, "C"}};
    for(const auto& pair: m1){
        std::cout<<pair.first<<" "<<pair.second<<"\n";
    }
}

void demoMap(){
    std::map <int, string> m = {{1, "A"}, {2, "B"}, {3, "C"}, {4, "D"}};
    
    std::cout<<"Map"<<"\n";
    for(const auto& pair: m){
        std::cout<<pair.first<<" "<<pair.second<<"\n";
    }
    
    int key;
    std::cout<<"Enter key: ";
    std::cin>>key;

    auto result = m.find(key);
    std::cout<<"Id: "<<result->first<<" "<<"Value: "<<result->second<<std::endl;
}

void displayVector(){
    std::vector<int> v1 = {10, 20, 30, 40, 50};

    std::cout<<"Vector"<<"\n";
    for(const auto& value : v1){
        std::cout<<value<<"\n";
    }
}

int main(){
    
    std::cout<<"Sum of two numbers: "<<sum(10, 20)<<"\n";

    std::cout<<"\n";
    displayMap();

    std::cout<<"\n";
    displayVector();

    std::cout<<"\n";
    demoMap();

    return 0;
}