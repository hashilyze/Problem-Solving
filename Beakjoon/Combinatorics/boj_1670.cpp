// Beakjoon 1670 - 정상 회담 2
// https://www.acmicpc.net/problem/1670

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
//types
using ll = long long;
// constants
constexpr int MAX_N = 10'000;
constexpr ll MOD = 987'654'321LL;
// variables
ll dp[MAX_N];

void init(){
    dp[0] = 1;
    for(int n = 2; n <= MAX_N; n += 2){
        for(int k = 0; k < n; k += 2){
            dp[n] = (dp[n] + (dp[k] * dp[n - k - 2]) % MOD) %MOD;
        }
    }
}


int main(void){
    FASTIO
    
    init();
    int n;
    std::cin >> n;
    std::cout << dp[n] << '\n';

    return 0;
}