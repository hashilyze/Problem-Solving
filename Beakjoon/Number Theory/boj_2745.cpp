// Beakjoon 2745 - 진법 변환
// https://www.acmicpc.net/problem/2745

#include <bits/stdc++.h>

// macros
#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);
// types
// constants
// variables
std::string N;
int B;


int main(void){
    FASTIO

    std::cin >> N >> B;
    int decimal = 0;
    for(char digit : N){
        decimal *= B;
        if(std::isdigit(digit)){ // 0 ~ 9
            decimal += digit - '0';
        } else { // A ~ Z (10 ~ 36)
            decimal += digit - 'A' + 10;
        }
    }
    std::cout << decimal;
}