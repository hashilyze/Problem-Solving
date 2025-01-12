// Beakjoon 6588 - 골드바흐의 추측
// https://www.acmicpc.net/problem/6588

#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
constexpr int SIZE = 1'000'000;
// variables
bool isPrimes[SIZE + 1];
std::vector<int> primes;


void init(){
    // 소수 배열 초기화
    std::memset(isPrimes, true, sizeof(isPrimes));
    isPrimes[0] = isPrimes[1] = false;
    for(int i = 2; i * i <= SIZE; ++i){
        if(isPrimes[i]){
            primes.push_back(i);

            for(int j = i * i; j <= SIZE; j += i){
                isPrimes[j] = false;
            }
        }
    }
}


int main(void){
    FASTIO
    init();

    int N;
    while(std::cin >> N){
        if(N == 0) break;

        int a = 0, b = 0;
        for(int p : primes) {
            if(isPrimes[N - p]){
                a = p; 
                b = N - p;
                break;
            }
        }

        if(a + b == N) std::cout << N << " = " << a << " + " << b << '\n';
        else std::cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}