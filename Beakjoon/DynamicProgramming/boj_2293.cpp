// Beakjoon 2293 - 동전 1
// https://www.acmicpc.net/problem/2293

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 100;
constexpr int MAX_K = 10'000;
// variables
int N, K;
int coins[MAX_N];
int dp[MAX_K + 1];


int solution(){
   dp[0] = 1;
   for(int i = 0; i < N; ++i){
      const int coin = coins[i];
      for(int x = coin; x <= K; ++x){
         dp[x] += dp[x - coin];
      }
   }
   return dp[K];
}

int main() { 
   FASTIO
   
   std::cin >> N >> K;
   for(int i = 0; i < N; ++i) std::cin >> coins[i];
   std::sort(coins, coins + N);
   std::cout << solution();

   return 0; 
}