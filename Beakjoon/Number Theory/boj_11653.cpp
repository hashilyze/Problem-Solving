// Beakjoon 11653 - 소인수분해
// https://www.acmicpc.net/problem/11653

#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
constexpr int SIZE = 10'000'000;
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

void solution(int n, std::vector<int>& outAns){
    // 소인수 분해
    int p = 2;
    while(n > 1){ 
        int flag = n % p;
        if (n % p == 0) {
            n /= p;
            outAns.push_back(p);
        } else {
            while(!isPrimes[++p]) continue;
        }
    }
}

int main(void){
    FASTIO
    init();

    int N;
    std::cin >> N;

    std::vector<int> ans;
    solution(N, ans);
    for(int x : ans) std::cout << x << '\n';

    return 0;
}