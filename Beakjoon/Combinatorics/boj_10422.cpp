// Beakjoon 10422 - 괄호
// https://www.acmicpc.net/problem/10422

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 5'000;
constexpr ll MOD = 1'000'000'007LL;
// variables
ll dp[MAX_N + 1];

void init(){
    dp[0] = 1;
    for(int n = 1; n <= MAX_N; ++n){
        ll& v = dp[n];
        for(int k = 0; k < n; ++k){
            v = (v + ((dp[k] * dp[n - k - 1]) % MOD)) % MOD;
        }
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
        if(n % 2) std::cout << 0 << '\n';
        else std::cout << dp[n >> 1] << '\n';
    }

    return 0;
}