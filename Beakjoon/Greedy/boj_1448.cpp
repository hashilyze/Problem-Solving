// Beakjoon 1448 - 삼각형 만들기
// https://www.acmicpc.net/problem/1448

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
int arr[1'000'000];

int main() { 
   FASTIO
   
   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> arr[i];
   std::sort(arr, arr + N);
   
   int max = -1;
   for(int i = N - 1; i >= 2; --i){
      if(arr[i - 2] + arr[i - 1] > arr[i]){
         max = arr[i - 2] + arr[i - 1] + arr[i];
         break;
      }   
   }
   std::cout << max;
   

   return 0; 
}