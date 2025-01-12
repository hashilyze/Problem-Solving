// Beakjoon 11653 - 소인수분해
// https://www.acmicpc.net/problem/11653

#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
// variables

void solution(int n, std::vector<int>& outAns){
    // 소인수 분해
    for(int p = 2; p <= n; ++p){
        while(n % p == 0){
            n /= p;
            outAns.push_back(p);
        }
    }
}

int main(void){
    FASTIO

    int N;
    std::cin >> N;

    std::vector<int> ans;
    solution(N, ans);
    for(int x : ans) std::cout << x << '\n';

    return 0;
}