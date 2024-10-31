// Beakjoon 2012 - 등수 매기기
// https://www.acmicpc.net/problem/2012

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_N = 500'000;
// variables
int N;
int rank[MAX_N + 1];


ll solution(){
    ll sum = 0LL;
    int expected = 1;
    for(int actual = 1; actual <= N; ++actual){
        while(rank[expected] == 0) ++expected;
        sum += std::abs(actual - expected);
        --rank[expected];
    }
    return sum;  
}

int main(void){
    FASTIO

    std::cin >> N;
    for(int i = 0; i < N; ++i) {
        int r;
        std::cin >> r;
        ++rank[r];
    }
    std::cout << solution();

    return 0;
}   