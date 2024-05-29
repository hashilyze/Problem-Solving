// Beakjoon 1149 - RGB거리
// https://www.acmicpc.net/problem/1149

#include <algorithm>
#include <cmath>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 1'000;
// variables
int dp[3][MAX_N];
int cost[3][MAX_N];

int main(void){
    FASTIO

    int N;
    std::cin >> N;
    for(int i = 0; i < N; ++i) std::cin >> cost[0][i] >> cost[1][i] >> cost[2][i];

    dp[0][0] = cost[0][0]; 
    dp[1][0] = cost[1][0]; 
    dp[2][0] = cost[2][0];
    for(int i = 1; i < N; ++i){
        dp[0][i] = std::min(dp[1][i - 1], dp[2][i - 1]) + cost[0][i];
        dp[1][i] = std::min(dp[2][i - 1], dp[0][i - 1]) + cost[1][i];
        dp[2][i] = std::min(dp[0][i - 1], dp[1][i - 1]) + cost[2][i];
    }
    std::cout << std::min({dp[0][N - 1], dp[1][N - 1], dp[2][N - 1]}) << '\n';


    return 0;
}