// Beakjoon 16563 - 어려운 소인수분해
// https://www.acmicpc.net/problem/16563

#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
using ll = long long;
// constants
constexpr int SIZE = 5'000'000;
// variables
int lpf[SIZE + 1]; // least prime factor
std::vector<int> primes;


void init(){
    std::memset(lpf, 0x00, sizeof(lpf));
    for(int i = 2; i <= SIZE; ++i){
        if(lpf[i] == 0){
            primes.push_back(i);
            lpf[i] = i;
        }

        for(int p : primes){
            if((ll)i * p >= SIZE) break;
            lpf[i * p] = p;
            if(i % p == 0) break;
        }
    }
}

void solution(int n){
    while(n > 1){
        std::cout << lpf[n] << ' ';
        n /= lpf[n];
    }
    std::cout << '\n';
}

int main(void){
    FASTIO
    init();

    int N;
    std::cin >> N;

    while(N--){
        int K;
        std::cin >> K;
        solution(K);
    }

    return 0;
}