// Beakjoon 2212 - 센서
// https://www.acmicpc.net/problem/2212

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
// variables
int N, K;
int arr[10'000];

int main(void){
   FASTIO
   
   std::cin >> N >> K;
   for(int i = 0; i < N; ++i) std::cin >> arr[i];
   std::sort(arr, arr + N);
   for(int i = 0; i < N - 1; ++i) arr[i] = arr[i + 1] - arr[i];
   std::sort(arr, arr + (N - 1));

   int sum = 0;
   for(int i = 0; i < N - K; ++i) sum += arr[i];
   std::cout << sum;

   return 0;
}   