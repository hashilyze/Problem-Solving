// Beakjoon 4948 - 베르트랑 공준
// https://www.acmicpc.net/problem/4948

#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
constexpr int SIZE = 123'456 * 2;
// variables
bool isPrimes[SIZE + 1];
int rangeSum[SIZE + 1];


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

    // 소수개수 누적합
    std::memset(rangeSum, 0x00, sizeof(rangeSum));
    for(int p = 2; p <= SIZE; ++p){
        rangeSum[p] = rangeSum[p - 1] + (isPrimes[p] ? 1 : 0);
    }
}

int solution(int n){
    // { p | n < p <= 2n }
    return rangeSum[2 * n] - rangeSum[n];
}

int main(void){
    FASTIO
    init();

    int N;
    while(std::cin >> N){
        if(N == 0) break;
        std::cout << solution(N) << '\n';
    }

    return 0;
}