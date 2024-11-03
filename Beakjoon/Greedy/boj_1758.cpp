// Beakjoon 1758 - 알바생 강호
// https://www.acmicpc.net/problem/1758

#include <algorithm>
#include <functional>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
// variables
int N;
int tips[100'000];


ll solution(){
   ll sum = 0LL;
   std::sort(tips, tips + N, std::greater<int>());
   for(int i = 0; i < N; ++i) sum += std::max(0, tips[i] - i);
   return sum;
}

int main(void){
   FASTIO

   std::cin >> N;
   for(int i = 0; i < N; ++i) std::cin >> tips[i];
   std::cout << solution();

   return 0;
}   