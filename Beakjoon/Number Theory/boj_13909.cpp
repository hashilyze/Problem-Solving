// Beakjoon 13909 - 창문 닫기
// https://www.acmicpc.net/problem/13909

#include <iostream>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
// variables


int main(void){
    FASTIO

    int N;
    std::cin >> N;

    int ans = 0;
    for(int i = 1; i * i <= N; ++i) ++ans;
    std::cout << ans;

    return 0;
}