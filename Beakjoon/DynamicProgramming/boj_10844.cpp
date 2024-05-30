// Beakjoon 10844번 - 쉬운 계단 수
// https://www.acmicpc.net/problem/10844

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100;
constexpr int MOD = 1'000'000'000;
// variables
int dp[10][MAX_N];


int main(void){
    FASTIO  

    for(int i = 1; i < 10; ++i) dp[i][0] = 1;
    for(int i = 1; i < MAX_N; ++i){
        dp[0][i] = dp[1][i - 1];
        for(int j = 1; j <= 8; ++j) dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % MOD;
        dp[9][i] = dp[8][i - 1];
    }

    int N, sum = 0;
    std::cin >> N;
    for(int i = 0; i < 10; ++i) sum = (sum + dp[i][N - 1]) % MOD;
    std::cout << sum << '\n';

    return 0;
}