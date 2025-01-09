// Beakjoon 2581 - 소수 
// https://www.acmicpc.net/problem/2581

#include <algorithm>
#include <cstring>
#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
constexpr int SIZE = 10'000;
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

    int min = SIZE, sum = 0;
    for(int x = M; x <= N; ++x){
        std::cin >> x;
        if(isPrimes[x]) {
            min = std::min(x, min);
            sum += x;
        }
    }

    if(sum == 0){
        std::cout << -1;
    } else{
        std::cout << sum << '\n' << min;
    }
    

    return 0;
}