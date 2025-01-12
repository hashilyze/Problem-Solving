// Beakjoon 1124 - 언더프라임
// https://www.acmicpc.net/problem/1124

#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
constexpr int SIZE = 100'000;
// variables
int lpfs[SIZE + 1];     // least prime factors
std::vector<int> primes;


void initLpf(int n){
    for(int i = 2; i <= n; ++i) {
        if(lpfs[i] == 0) {
            lpfs[i] = i;
            primes.push_back(i);
        }
        for(int p : primes){
            if(i * p > n) break;
            lpfs[i * p] = p;
            if(lpfs[i] == p) break;
        }
    }
}

int countPrimeFactors(int n){
    int cnt = 0;
    while(n > 1){
        ++cnt;
        n /= lpfs[n];
    }
    return cnt;
}

inline bool isPrime(int n) { 
    return lpfs[n] == n;
}

int main(void){
    FASTIO
    initLpf(SIZE);
    
    int A, B;
    std::cin >> A >> B;

    int cnt = 0;
    for(int i = A; i <= B; ++i){
        if(isPrime(countPrimeFactors(i))) ++cnt;
    }
    std::cout << cnt;

    return 0;
}