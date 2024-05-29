// Beakjoon 1932 - 정수 삼각형
// https://www.acmicpc.net/problem/1932

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 500;
// variables
int dp[MAX_N][MAX_N];

int main(void){
    FASTIO  

    int N;
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= i; ++j){
            std::cin >> dp[i][j];
        }
    }
    for(int i = 1; i < N; ++i){
        dp[i][0] += dp[i - 1][0];
        for(int j = 1; j < i; ++j){
            dp[i][j] += std::max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
        dp[i][i] += dp[i - 1][i - 1];
    }
    
    int max = 0;
    for(int i = 0; i < N; ++i) max = std::max(max, dp[N - 1][i]);
    std::cout << max << '\n';

    return 0;
}