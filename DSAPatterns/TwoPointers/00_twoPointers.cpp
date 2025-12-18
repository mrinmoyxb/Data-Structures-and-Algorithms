#include <iostream>
#include <cmath>

//* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>QUESTION 1:
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

//* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>QUESTION 2:
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

//! practice 
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

//* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>QUESTION 3:
//! |max(a,b,c)-min(a,b,c)| should be minimum 
//! Bruteforce approach:
int max(int n1, int n2, int n3){
    if(n1 > n2){
        if(n1>n3){
            return n1;
        }else{
            return n3;
        }
    }else{
        if(n2>n3){
            return n2;
        }else{
            return n3;
        }
    }
}

int min(int n1, int n2, int n3){
    if(n1<n2){
        if(n1<n3){
            return n1;
        }else{
            return n3;
        }
    }else{
        if(n2<n3){
            return n2;
        }else{
            return n3;
        }
    }
}

void problem2(int arr1[], int arr2[], int arr3[], int size1, int size2, int size3){
    int result = INT_MAX;
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            for(int k=0; k<size3; k++){
                int ans = std::abs(max(arr1[i], arr2[j], arr3[k]) - min(arr1[i], arr2[j], arr3[k]));
                if(ans<result)
                    result = ans;
                    std::cout<<"("<<arr1[i]<<", "<<arr2[j]<<", "<<arr3[k]<<")"<<std::endl;
                    std::cout<<"max: "<<max(arr1[i], arr2[j], arr3[k])<<", "<<"min: "<<min(arr1[i], arr2[j], arr3[k])<<", "<<"ans: "<<ans<<std::endl;
                    if(ans==1){
                        std::cout<<"YAYYYY"<<std::endl;
                    }
            }
        }
    }

    std::cout<<"Minimum difference: "<<result<<std::endl;
}

//! Optimised answer: 
int max3(int n1, int n2, int n3){
    return std::max(n1, std::max(n2, n3));
}

int min3(int n1, int n2, int n3){
    return std::min(n1, std::min(n2, n3));
}


void problem2Optimised(int arr1[], int arr2[], int arr3[], int size1, int size2, int size3) {

    int i = 0, j = 0, k = 0;
    int n1 = size1, n2 = size2, n3 = size3;

    int ans = INT_MAX;

    while(i<n1 && j<n2 && k<n3){
        int currentMin = min3(arr1[i], arr2[j], arr3[k]);
        int currentMax = max3(arr1[i], arr2[j], arr3[k]);
        ans = std::min(ans, std::abs(currentMax-currentMin));
        if(currentMin == arr1[i]) i++;
        else if(currentMin == arr2[j]) j++;
        else k++;
    }

    std::cout<<ans<<std::endl;
}

int main(){
    int arr1[4] = {2, 4, 6, 10};
    int arr2[3] = {1, 2, 3};
    int arr3[5] = {4, 5, 8, 9, 12};
    problem2Optimised(arr1, arr2, arr3, 4, 3, 5);
    return 0;
}