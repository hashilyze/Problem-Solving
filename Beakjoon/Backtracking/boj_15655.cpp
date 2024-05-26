// Beakjoon 15655 - N과 M (6)
// https://www.acmicpc.net/problem/15655


#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
constexpr int MAX_N = 8;
// variables
int n, m;
ivec seq;
int arr[MAX_N];


void solve(int pos, int size, int left){
    if(left == 0) {
        for(int elem : seq) std::cout << elem << ' ';
        std::cout << '\n';
        return;
    }
    for(int i = pos; i < size - left + 1; ++i){
        seq.push_back(arr[i]);
        solve(i + 1, size, left - 1);
        seq.pop_back();
    }
}

int main(void){
    FASTIO

    std::cin >> n >> m;
    seq.reserve(MAX_N);

    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    std::sort(arr, arr + n);

    solve(0, n, m);

    return 0;
}