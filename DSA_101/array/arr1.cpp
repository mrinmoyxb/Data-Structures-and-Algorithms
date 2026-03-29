#include <iostream>
#include <vector>

void maxElement(std::vector<int> v){
    int max = INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    std::cout<<"Max: "<<max<<std::endl;
}

void secondLargest(std::vector<int> v){
    int largest = INT_MIN, sl = INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(v[i] > largest){
            largest = v[i];
        }
    }

    for(int i=0; i<v.size(); i++){
        if(v[i] != largest && v[i]>sl){
            sl = v[i];
        }
    }

    std::cout<<"Largest: "<<largest<<std::endl;
    std::cout<<"Second largest: "<<sl<<std::endl;
}

void secondLargestOptimal(std::vector<int> v){
    int largest = INT_MIN, sl = INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(v[i]>largest){
            sl = largest;
            largest = v[i];
        }

        if(v[i]>sl && v[i]<largest){
            sl = v[i];
        }
    }

    std::cout<<"largest: "<<largest<<std::endl;
    std::cout<<"second largest: "<<sl<<std::endl;
}

void secondSmallest(std::vector<int> v){
    int smallest = INT_MAX, ss = INT_MAX;
    for(int i=0; i<v.size(); i++){
        if(v[i]<smallest){
            ss = smallest;
            smallest = v[i];
        }

        if(v[i]<ss && v[i]>smallest){
            ss = v[i];
        }
    }

    std::cout<<"smallest: "<<smallest<<std::endl;
    std::cout<<"second smallest: "<<ss<<std::endl;
}

bool isSorted(std::vector<int> v){
    for(int i=1; i<v.size(); i++){
        if(v[i] > v[i-1]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

void removeDuplicates(std::vector<int> v){
    int i = 0;
    int j = i+1;
    while(j<v.size() && i<v.size()){
        if(v[i] == v[j]){
            j+=1;
        }else{
            i+=1;
            v[i] = v[j];
            j+=1;
        }
    }

    for(auto value: v){
        std::cout<<value<<" ";
    }
}


int main(){
    std::vector<int> v = {1, 1, 2, 2, 2, 3, 3};
    std::cout<<"\nArray: "<<std::endl;
    for(auto value: v){
        std::cout<<value<<" ";
    }

    std::cout<<"\nDuplicate: "<<std::endl;
    removeDuplicates(v);
    return 0;
}