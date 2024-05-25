// Beakjoon 17435 - 합성함수와 쿼리
// https://www.acmicpc.net/problem/17435


#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 200'000;
constexpr int MAX_DEPTH = 500'000;
const int MAX_LEVEL = (int)std::floor(std::log2(MAX_DEPTH));
// variables
int n;
int parents[20][MAX_N + 1];


void build(){
    for(int i = 1; i <= MAX_LEVEL; ++i){
        for(int u = 1; u <= n; ++u){
            parents[i][u] = parents[i - 1][parents[i -1][u]];
        }
    }
}

int solve(int n, int x){
    for(int i = MAX_LEVEL; i >= 0; --i){
        if((n >> i) & 1){
            x = parents[i][x];
        }
    }
    return x;
}

int main(void){
    FASTIO

    std::cin >> n;
    for(int i = 1; i <= n; ++i) std::cin >> parents[0][i];
    build();

    int q;
    std::cin >> q;
    while(q--){
        int x, n;
        std::cin >> n >> x;
        std::cout << solve(n, x) << '\n';
    }

    return 0;
}