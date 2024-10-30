// Beakjoon 1449 - 수리공 항승
// https://www.acmicpc.net/problem/1449

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 1'000;
// variables
int N, L;
int sinks[MAX_N];

int solution(){
   int ret = 0;
   
   std::sort(sinks, sinks + N);
   
   int cur = 0;
   while(cur < N){
      ++ret;
      int limit = sinks[cur] + L;
      while(cur < N && sinks[cur] < limit){
         ++cur;
      }
   }

   return ret;
}

int main() { 
   FASTIO

   std::cin >> N >> L;
   for(int i = 0; i < N; ++i) std::cin >> sinks[i];
   std::cout << solution();

   return 0; 
}