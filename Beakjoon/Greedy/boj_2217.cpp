// Beakjoon 2217 - 로프 
// https://www.acmicpc.net/problem/2217

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
int W[100'000];


int solution(){
   int max = 0;
   for(int i = 0; i < N; ++i) max = std::max(max, W[i] * (N - i));
   return max;
}

int main(void){
   FASTIO

   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> W[i];
   std::sort(W, W + N);
   std::cout << solution();

   return 0;
}   