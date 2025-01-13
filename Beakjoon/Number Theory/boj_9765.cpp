// Beakjoon 9765 - 여섯 방정식
// https://www.acmicpc.net/problem/9765


#include <cstring>
#include <iostream>
#include <numeric>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
// variables


int main(void){
    FASTIO

    ll c1, c2, c3, c4, c5, c6;
    std::cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
    
    ll x1, x2, x3, x5, x6, x7;
    
    x2 = std::gcd(c1, c5);
    x1 = c1 / x2;
    x3 = c5 / x2;

    x6 = std::gcd(c3, c6);
    x7 = c3 / x6;
    x5 = c6 / x6;

    std::cout << x1 << ' ' 
        << x2 << ' ' 
        << x3 << ' '  
        << x5 << ' ' 
        << x6 << ' ' 
        << x7;

    return 0;
}