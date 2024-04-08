// Beakjoon 1735번 - 분수 합
// https://www.acmicpc.net/problem/1735

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// tpyes
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void){
    FASTIO
    int a1, b1, a2, b2;
    std::cin >> a1 >> b1 >> a2 >> b2;
    
    int a = a1 * b2 + a2 * b1, b = b1 * b2;
    int d = a < b ? gcd(b, a) : gcd(a, b);
    
    std::cout << a / d << " " << b / d << '\n';


    return 0;
}