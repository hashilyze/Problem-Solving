// Beakjoon 15652 - N과 M (4)
// https://www.acmicpc.net/problem/15652

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
    for(int i = n; i <= N; ++i){
        perm.push_back(i);
        countCombination(i, N, m - 1, perm);
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