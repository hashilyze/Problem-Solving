// Beakjoon 1929 - 소수 구하기
// https://www.acmicpc.net/problem/1929

#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
constexpr int SIZE = 1'000'000;
// variables
bool isPrimes[SIZE + 1];


void init(){
    // 소수 배열 초기화
    std::memset(isPrimes, true, sizeof(isPrimes));
    isPrimes[0] = isPrimes[1] = false;
    for(int p = 2; p * p <= SIZE; ++p){
        if(!isPrimes[p]) continue;
        for(int n = p * p; n <= SIZE; n += p){
            isPrimes[n] = false;
        }
    }
}

int main(void){
    FASTIO
    init();

    int M, N;
    std::cin >> M >> N;
    for(int x = M; x <= N; ++x){
        std::cin >> x;
        if(isPrimes[x]) std::cout << x << '\n';
    }

    return 0;
}