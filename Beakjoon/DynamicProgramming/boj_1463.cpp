// Beakjoon 1463번 - 1로 만들기
// https://www.acmicpc.net/problem/1463

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 1'000'000;
// variables
int dp[MAX_N + 1];

int main(void){
    FASTIO  

    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int i = 4; i <= MAX_N; ++i){
        int min = dp[i - 1];
        if(i % 2 == 0) min = std::min(min, dp[i / 2]);
        if(i % 3 == 0) min = std::min(min, dp[i / 3]);
        dp[i] = min + 1;
    }

    int N;
    std::cin >> N;
    std::cout << dp[N] << '\n';

    return 0;
}