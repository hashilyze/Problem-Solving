// Beakjoon 2156번 - 포도주 시식
// https://www.acmicpc.net/problem/2156

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 10'000;
// variables
int s[MAX_N + 1];
int dp[MAX_N + 1];


int main(void){
    FASTIO  

    int N;
    std::cin >> N;
    for(int i = 1; i <= N; ++i) std::cin >> s[i];

    dp[1] = s[1];
    dp[2] = s[1] + s[2];
    for(int i = 3; i <= N; ++i){
        dp[i] = std::max({
            dp[i - 1], 
            dp[i - 2] + s[i],
            dp[i - 3] + s[i - 1] + s[i]
        });
    }
    std::cout << dp[N] << '\n';

    return 0;
}