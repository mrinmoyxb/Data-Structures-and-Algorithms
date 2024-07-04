#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        vector<int> mergeArr;

        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                mergeArr.push_back(nums1[i++]);
            }
            else{
                mergeArr.push_back(nums2[j++]);
            }
        }

        while(i<m){
            mergeArr.push_back(nums1[i++]);
        }

        while(j<n){
            mergeArr.push_back(nums2[j++]);
        }


        cout<<"\nv3: "<<endl;
        for(int i= 0; i<mergeArr.size(); i++){
            cout<<mergeArr[i]<<" ";
        }
    }

int main(){

    vector<int> v1 = {1, 3, 9, 10};
    vector<int> v2 = {2, 8, 12};

    cout<<"\nv1: "<<endl;
    for(int i= 0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }

    cout<<"\nv2: "<<endl;
    for(int i= 0; i<v2.size(); i++){
        cout<<v2[i]<<" ";
    }


    merge(v1, 4, v2, 3);

    
    return 0;
}