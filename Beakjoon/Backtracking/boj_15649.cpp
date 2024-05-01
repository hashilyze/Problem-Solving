// Beakjoon 15649 - N과 M (1)
// https://www.acmicpc.net/problem/15649

#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
using bvec = std::vector<bool>;


void countPermutation(int n, int m, ivec& perm, bvec& flag){
    if(m == 0){
        for(auto elem : perm) std::cout << elem << ' ';
        std::cout << '\n';
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(flag[i - 1]) continue;
        perm.push_back(i);
        flag[i - 1] = true;
        countPermutation(n, m - 1, perm, flag);
        flag[i - 1] = false;
        perm.pop_back();
    }
}


int main(void){
    FASTIO

    int n, m;
    std::cin >> n >> m;
    ivec perm;
    bvec flag(n);
    
    countPermutation(n, m, perm, flag);

    return 0;
}