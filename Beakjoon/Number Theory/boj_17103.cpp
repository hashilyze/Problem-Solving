// Beakjoon 17103 - 골드바흐 파티션
// https://www.acmicpc.net/problem/17103

#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
using ll = long long;
// constants
constexpr int SIZE = 1'000'000;
// variables
std::vector<int> primes;
bool isPrimes[SIZE + 1];


void init(){
    std::memset(isPrimes, true, sizeof(isPrimes));
    isPrimes[0] = isPrimes[1] = false;
    for(int i = 2; i <= SIZE; ++i){
        if(isPrimes[i]){
            primes.push_back(i);
        }
        for(int p : primes){
            if((ll)i * p >= SIZE) break;
            isPrimes[i * p] = false;
            if(i % p == 0) break;
        }
    }
}

int solution(int n){
    int cnt = 0;
    for(int p : primes){
        if(p > n - p) break;
        if(isPrimes[n - p]) ++cnt;
    }
    return cnt;
}

int main(void){
    FASTIO
    init();

    int T;
    std::cin >> T;

    while(T--){
        int N;
        std::cin >> N;
        std::cout << solution(N) << '\n';
    }

    return 0;
}