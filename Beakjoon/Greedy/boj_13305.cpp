// Beakjoon 13305 - 주유소
// https://www.acmicpc.net/problem/13305

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 100'000;
// variables
int N;
int oilbanks[MAX_N];
int lanes[MAX_N];

ll solution(){
   ll ret = 0LL;
   
   int min = 1'000'000'000 + 1;
   for(int i = 0; i < N - 1; ++i){
      min = std::min(min, oilbanks[i]);
      ret += (ll)lanes[i] * min;
   }

   return ret;
}

int main() { 
   FASTIO

   std::cin >> N;
   for(int i = 0; i < N - 1; ++i) std::cin >> lanes[i]; 
   for(int i = 0; i < N; ++i) std::cin >> oilbanks[i];
   std::cout << solution();

   return 0; 
}