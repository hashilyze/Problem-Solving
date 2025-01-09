// Beakjoon 1978 - 소수 찾기
// https://www.acmicpc.net/problem/1978

#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
constexpr int SIZE = 1'000;
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


    int N, X, cnt = 0;
    std::cin >> N;
    while(N--){
        std::cin >> X;
        if(isPrimes[X]) ++cnt;
    }
    std::cout << cnt;

    return 0;
}