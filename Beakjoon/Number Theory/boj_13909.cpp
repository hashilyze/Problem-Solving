// Beakjoon 13909 - 창문 닫기
// https://www.acmicpc.net/problem/13909

#include <cmath>
#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
// variables


int main(void){
    FASTIO

    int N; std::cin >> N;
    std::cout << (int)std::sqrt(N);

    return 0;
}