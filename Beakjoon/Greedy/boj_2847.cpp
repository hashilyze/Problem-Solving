// Beakjoon 2847 - 게임을 만든 동준이
// https://www.acmicpc.net/problem/2847

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
int arr[100];

int solution(){
   int sum = 0;
   int limit = arr[N - 1];
   for(int i = N - 2; i >= 0; --i){
      limit = std::min(limit - 1, arr[i]);
      sum += std::max(0, arr[i] - limit);
   }
   return sum;
}

int main(void){
   FASTIO

   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> arr[i];
   std::cout << solution();

   return 0;
}   