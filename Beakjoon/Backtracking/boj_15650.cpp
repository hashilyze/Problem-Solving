// Beakjoon 15651 - N과 M (3)
// https://www.acmicpc.net/problem/15651

#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;


void countCombination(int n, int N, int m, ivec& perm){
    if(m == 0){
        for(auto elem : perm) std::cout << elem << ' ';
        std::cout << '\n';
        return;
    }
    for(int i = n; i <= N - m + 1; ++i){
        perm.push_back(i);
        countCombination(i + 1, N, m - 1, perm);
        perm.pop_back();
    }
}


int main(void){
    FASTIO

    int n, m;
    std::cin >> n >> m;
    ivec perm; perm.reserve(8);
    countCombination(1, n, m, perm);

    return 0;
}