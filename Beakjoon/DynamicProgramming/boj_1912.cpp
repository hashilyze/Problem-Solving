// Beakjoon 1912 - 연속합
// https://www.acmicpc.net/problem/1912

#include <cmath>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100'000;
// variables
int dp[MAX_N + 1];

int main(void){
    FASTIO

    int N;
    std::cin >> N;
    for(int i = 1; i <= N; ++i) std::cin >> dp[i];
    for(int i = 2; i <= N; ++i) dp[i] += std::max(0, dp[i - 1]);
    for(int i = 2; i <= N; ++i) dp[i] = std::max(dp[i - 1], dp[i]);
    std::cout << dp[N] << '\n';

    return 0;
}