// Beakjoon 11423 - Primes
// https://www.acmicpc.net/problem/11423

#include <algorithm>
#include <iostream>
#include <iterator>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
//constexpr int SIZE = 10'000'000;
constexpr int SIZE = 1'000;
// variables
int rangeSum[SIZE + 1];


void initErathos(){
    std::fill(std::begin(rangeSum), std::end(rangeSum), 1);
    rangeSum[0] = rangeSum[1] = 0;
    for(int i = 2; i * i <= SIZE; ++i){
        if(rangeSum[i] == 0) continue;

        for(int j = i * i; j <= SIZE; j += i){
            rangeSum[j] = 0;
        }
    }
}
void initRangeSum(){
    for(int i = 1; i <= SIZE; ++i){
        rangeSum[i] += rangeSum[i - 1];
    }
}


int main(void){
    FASTIO
    initErathos();
    initRangeSum();

    int m, n;
    while(std::cin >> m >> n){
        std::cout << rangeSum[n] - rangeSum[m - 1] << "\n\n";
    }
    

    return 0;
}