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

int solution(int n){
    int cnt = 0;
    for(int x = n + 1; x <= 2 * n; ++x){
        if(isPrimes[x]) ++cnt;
    }
    return cnt;
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