// Beakjoon 2998 - 8진수
// https://www.acmicpc.net/problem/2998

#include <bits/stdc++.h>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
// variables


int main(void){
    FASTIO

    std::string bin, oct = "";
    std::cin >> bin;

    int len = 0, val = 0;
    while(!bin.empty()){
        val += (bin.back() - '0') << len;
        bin.pop_back();

        if(++len == 3){
            oct += val + '0';
            len = val = 0;
        }
    }
    if(len > 0){
        oct += val + '0';
    }

    std::reverse(oct.begin(), oct.end());
    std::cout << oct;

    return 0;
}