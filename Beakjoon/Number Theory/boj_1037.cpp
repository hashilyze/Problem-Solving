// Beakjoon 1037 - 약수
// https://www.acmicpc.net/problem/1037

#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
// variables


int main(void){
    FASTIO

    int M;
    std::cin >> M;
    
    int min = 0x7FFFFFFF, max = 0x80000000;
    while(M--){
        int x;
        std::cin >> x;
        min = std::min(min, x);
        max = std::max(max, x);
    }
    std::cout << min * max;

    return 0;
}