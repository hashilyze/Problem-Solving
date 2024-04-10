// Beakjoon 17087번 - 숨바꼭질 6
// https://www.acmicpc.net/problem/17087

#include <iostream>
#include <cmath>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void){
    FASTIO

    int n, s, d = 0;
    std::cin >> n >> s;
    for(int i = 0; i < n; ++i){
        int a;
        std::cin >> a;
        a = std::abs(a - s);

        if(d < a) std::swap(d, a);
        d = gcd(d, a);
    }
    std::cout << d << '\n';

    return 0;
}