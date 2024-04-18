// Beakjoon 2725번 - 보이는 점의 개수
// https://www.acmicpc.net/problem/2725

#include <iostream>
#include <set>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 1'000;
// variables
int dp[MAX_N + 1];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void){
    FASTIO

    int c;
    std::cin >> c;

    dp[1] = 3;
    for(int y = 2; y <= MAX_N; ++y){
        for(int x = 0; x < y; ++x){
            if(gcd(x, y) == 1){
                dp[y] += 2;
            }
        }
    }
    for(int i = 1; i <= MAX_N; ++i) dp[i] += dp[i - 1];


    while(c--){
        int n;
        std::cin >> n;
        std::cout << dp[n] << '\n';
    }

    return 0;
}