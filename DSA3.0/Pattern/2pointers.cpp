#include <iostream>
#include <vector>


// std::pair<int, int> twoPointers1(std::vector<int> v, int key){
//     for(int i=0; i<v.size()-1; i++){
//         for(int j=i+1; j<v.size(); j++){
//             if(v[i]+v[j] == key ){
//                 std::pair<int, int> ans = {i, j};
//                 return ans;
//             }
//         }
//     }
// }

int main(){

    int arr[6] = {1, 1, 2, 3, 3, 4};
    for(int i=0; i<6; i++){
        if(arr[i]==arr[i-1]) continue;
        std::cout<<arr[i]<<" ";
    }
    return 0;
}