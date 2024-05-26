// Beakjoon 15664 - N과 M (10)
// https://www.acmicpc.net/problem/15664


#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 8;
// variables
int n, m;
int arr[MAX_N];

void solve(int pos, int size, int left, const std::string& str){
    if(left == 0) {
        std::cout << str << '\n';
        return;
    }
    for(int i = pos; i < size - left + 1; ++i){
        solve(i + 1, size, left - 1, str + std::to_string(arr[i]) + " ");
        while(i + 1 < size && arr[i] == arr[i + 1]) ++i;
    }
}

int main(void){
    FASTIO

    std::cin >> n >> m;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    std::sort(arr, arr + n);
    solve(0, n, m, "");

    return 0;
}