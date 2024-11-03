// Beakjoon 1041 - 주사위
// https://www.acmicpc.net/problem/1041

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
using ll = long long;
// variables
ll N;
int A, B, C, D, E, F;


ll solution(){
   if(N == 1){
      int min5 = (A + B + C + D + E + F) - std::max({A, B, C, D, E, F});
      return min5;
   }

   int min1 = std::min({A, B, C, D, E, F});
   int min2 = std::min({
      A + B, A + C, A + D, A + E,
      B + C, B + D, B + F,
      C + E, C + F,
      D + E, D + F,
      E + F
   });
   int min3 = std::min({
      A + B + C, A + B + D, A + C + E, A + D + E,
      F + B + C, F + B + D, F + C + E, F + D + E
   });
   return min3 * 4 
      + min2 * (8 * (N - 2) + 4)
      + min1 * ((N - 2) * (N - 2) + (N - 2) * (N - 1) * 4);
}

int main(void){
   FASTIO
   
   std::cin >> N;
   std::cin >> A >> B >> C >> D >> E >> F;
   std::cout << solution();

   return 0;
}   