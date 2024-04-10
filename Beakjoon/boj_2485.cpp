// Beakjoon 2485번 - 가로수
// https://www.acmicpc.net/problem/2485

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(void){
    FASTIO

    int n, d = 0;
    std::cin >> n;

    int min, max, prev;
    std::cin >> prev;
    min = prev;
    for(int i = 1; i < n; ++i){
        int s;
        std::cin >> s;
        d = (s - prev) >= d ? gcd((s - prev), d) : gcd(d, (s - prev));
        prev = s;
    }
    max = prev;
    
    std::cout << (max - min) / d + 1 - n << '\n';

    return 0;
}