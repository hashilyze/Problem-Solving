// Beakjoon 16112 - 5차 전직
// https://www.acmicpc.net/problem/16112

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
// variables
int N, K;
int arr[300'000];


ll solution(){
   ll sum = 0LL;
   std::sort(arr, arr + N);
   for(int i = 0; i < N; ++i) sum += (ll)arr[i] * std::min(i, K);
   return sum;
}

int main() { 
   FASTIO
   
   std::cin >> N >> K;
   for(int i = 0; i < N; ++i) std::cin >> arr[i];
   std::cout << solution();

   return 0; 
}