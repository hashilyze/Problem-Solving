// Beakjoon 1904 - 01타일
// https://www.acmicpc.net/problem/1904

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 1'000'000;
constexpr int MOD = 15746;
// variables
int dp[MAX_N];


int main(void){
    FASTIO

    dp[0] = 1; dp[1] = 2;
    for(int i = 2; i < MAX_N; ++i) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    int N;
    std::cin >> N;
    std::cout << dp[N - 1] << '\n';

    return 0;
}