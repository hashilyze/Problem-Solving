// Beakjoon 2960 - 에라토스테네스의 체
// https://www.acmicpc.net/problem/2960

#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
constexpr int SIZE = 1'000;
// variables
bool isPrimes[SIZE + 1];


int solution(int n, int k){
    std::memset(isPrimes, true, sizeof(isPrimes));
    isPrimes[0] = isPrimes[1] = false;
    for(int p = 2; p <= n; ++p){
        if(!isPrimes[p]) continue;
        if(--k == 0) return p;

        for(int x = p * p; x <= n; x += p){
            if(!isPrimes[x]) continue;
            if(--k == 0) return x;

            isPrimes[x] = false;
        }
    }
    return -1;
}

int main(void){
    FASTIO

    int N, K;
    std::cin >> N >> K;
    std::cout << solution(N, K);

    return 0;
}