// Beakjoon 6718 - Goldbach’s conjecture
// https://www.acmicpc.net/problem/6718


#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 0x01 << 15;
// variables
bool isPrimes[SIZE + 1];


void initErathos(int n){
    std::memset(isPrimes, 0x01, sizeof(isPrimes));
    isPrimes[0] = isPrimes[1] = false;
    for(int i = 2; i * i <= n; ++i){
        if(!isPrimes[i]) continue;
        for(int j = i * i; j <= n; j += i){
            isPrimes[j] = false;
        }
    }
}

int main(void){
    FASTIO
    initErathos(SIZE);

    int N;
    while(std::cin >> N){
        if(N == 0) break;

        int cnt = 0;
        for(int i = 2; 2 * i <= N; ++i){
            if(isPrimes[i] && isPrimes[N - i]) {
                ++cnt;
            }
        }
        std::cout << cnt << '\n';
    }

    return 0;
}