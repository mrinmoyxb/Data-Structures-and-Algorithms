#include <iostream>
#include <climits>
using namespace std;

// void slidingWindow(int *arr, int size, int windowSize){
//     int currentSum = 0;
//     int maxSum = INT_MIN;

//     int start = 0;
//     int end = start+windowSize;
//     int final = (size-windowSize);

//     while(start<=final){
//         int startVar = arr[start];
//         for(int i=start; i<end; i++){
//             currentSum += arr[i];
//         }
//         if(maxSum<=currentSum){
//             maxSum = currentSum;
//         }
//         start += 1;
//     }

//     cout<<"Max: "<<maxSum<<endl;

// }

// int main(){
//     int arr[9] = {11, 6, 7, 10, 6, 3,11, 0, 20};
//     slidingWindow(arr, 9, 4);
//     return 0;
// }

int maxSum(int arr[], int k, int n, int &start, int &end)
{
 
  int maximumSum = 0;
  int currentSum = 0;
  for (int i=0;i<k;i++)
  {
    currentSum += arr[i];
  }

  maximumSum = currentSum;
  start = 0;
  end = k - 1;
  for (int i=k;i<n;i++)
  {
    currentSum += arr[i] - arr[i-k];
    if (currentSum > maximumSum)
    {
      maximumSum = currentSum;
      start = i - k + 1;
      end = i; 
    } 
  }
  return maximumSum;
}

// driver code
int main()
{
  int start = 0;
  int end = 0;
  int arr[] = {6, 2, -1, 9, 1, -2};
  int k = 3;
  int n = (sizeof(arr)/sizeof(*arr));
  int maxsum = maxSum(arr, k, n, start, end);
  cout << "The maximum sum is " << maxsum;
  cout << " from position " << start << " till " << end << endl;
  return 0;
}