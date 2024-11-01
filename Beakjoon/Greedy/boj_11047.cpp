// Beakjoon 11047 - 동전 0
// https://www.acmicpc.net/problem/11047

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 10;
// variables
int N, K;
int coins[MAX_N];


int solution(){
   int cnt = 0;
   for(int i = N - 1; i >= 0; --i){
      int coin = coins[i];
      int d = K / coin;
      if(d) {
         cnt += d;
         K %= coin;
      }
   }
   return cnt;
}

int main() { 
   FASTIO
   
   std::cin >> N >> K;
   for(int i = 0; i < N; ++i) std::cin >> coins[i];
   std::cout << solution();

   return 0; 
}