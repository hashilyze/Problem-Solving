// Beakjoon 10978 - 기숙사 재배정
// https://www.acmicpc.net/problem/10978

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 20;
// variables
ll dp[MAX_N + 1];

void init(){
    dp[0] = dp[1] = 0;
    dp[2] = 1;
    for(int n = 3; n <= MAX_N; ++n){
        dp[n] = (n - 1) * (dp[n - 1] + dp[n - 2]);
    }
}

int main(void){
    FASTIO
    init();

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::cout << dp[n] << '\n';
    }

    return 0;
}