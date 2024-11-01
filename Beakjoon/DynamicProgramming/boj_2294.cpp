// Beakjoon 2294 - 동전 2
// https://www.acmicpc.net/problem/2294

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
   for(int x = 1; x <= K; ++x){
      dp[x] = 10'001;
      for(int i = 0; i < N; ++i){
         const int coin = coins[i];
         if(x < coin) break;
         dp[x] = std::min(dp[x], dp[x - coin] + 1);
      }
   }
   return dp[K] == 10'001 ? -1 : dp[K];
}

int main() { 
   FASTIO
   
   std::cin >> N >> K;
   for(int i = 0; i < N; ++i) std::cin >> coins[i];
   std::sort(coins, coins + N);
   std::cout << solution();

   return 0; 
}