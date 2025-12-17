#include <iostream>

//! move zeroes to left
void swapZeroesToRight(int arr[], int size){
    int slow = 0;
    int fast = 0;
    while(fast<size){
        if(arr[fast]!=0){
            std::swap(arr[slow], arr[fast]);
            slow++;
            fast++;
        }else{
            fast++;
        }
    }

    std::cout<<"\nArray: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
}

//! find the no. of pairs whose sum = k
//! Conditions: array is sorted and there are no duplicates
void findPairsOfTarget(int arr[], int size, int target){
    int start = 0;
    int end = size-1;

    while(start<end){
        int sum = arr[start] + arr[end];
        if(sum==target){
            std::cout<<"("<<arr[start]<<", "<<arr[end]<<")"<<std::endl;
            start+=1;
            end-=1;
        }
        else if(sum<target){
            start+=1;
        }
        else{
            end-=1;
        }
    }
}

//! find the no. of pairs whose sum = k
//! Better approach
void findPairsOfTargetOptimized(int arr[], int size, int target){
    int left = 0;
    int right = size-1;

    while(left<right){
        int sum = arr[left]+arr[right];

        if(sum==target){
            
            // duplicates between left and right like [2, 2, 2, 2, 2], if target = 4
            if(arr[left]==arr[right]){
                int count = right-left+1;
                int pairs = count * (count-1)/2;
                std::cout<<"Pairs: "<<pairs<<std::endl;
                for(int i=0; i<pairs; i++){
                    std::cout<<"("<<arr[left]<<", "<<arr[left]<<")"<<std::endl;
                }
                break;
            }

            int leftCount = 1, rightCount = 1;

            while(left+1 < right && arr[left]==arr[left+1]){
                leftCount+=1;
                left++;
            }

            while(right-1 > left && arr[right]==arr[right-1]){
                rightCount++;
                right--;
            }

            int count = leftCount*rightCount;
            std::cout<<count<<std::endl;

            for(int i=0; i<count; i++){
                std::cout<<"("<<arr[left]<<", "<<arr[right]<<")"<<std::endl;
            }

            left++;
            right--;
        }
        else if(sum>target){
            right--;
        }
        else{
            left++;
        }
    }
}

void practice1(int arr[], int size, int target){
    int left = 0;
    int right = size-1;
    while(left<right){
        int sum = arr[left] + arr[right];

        if(sum==target){

            // for [2, 2, 2, 2], similar start and end, target = 4
            if(arr[left]==arr[right]){
                int count = right - left + 1;
                int pairs = count * (count-1)/2;
                std::cout<<"Pairs: "<<pairs<<std::endl;
                break;
            }

            // for repeated values like [1, 1, 1, 3, 3], target = 4
            int leftCount = 1, rightCount = 1;
            while(left+1 < right && arr[left]==arr[left+1]){
                leftCount+=1;
                left++;
            }

            while(right-1 > left && arr[right]==arr[right-1]){
                rightCount+=1;
                right--;
            }

            int count = leftCount*rightCount;
            std::cout<<"Count: "<<count<<std::endl;

            left++;
            right--;
        }
        else if(sum>target){
            right--;
        }
        else{
            left++;
        }
    }
}

int main(){
    int arr[9] = {1, 2, 2, 2, 2, 3, 4, 5, 5};
    std::cout<<"\nArray: "<<std::endl;
    for(int i=0; i<9; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    
    findPairsOfTargetOptimized(arr, 9, 7);
    return 0;
}