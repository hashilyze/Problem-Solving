// Beakjoon 2609번 - 최대공약수와 최소공약수
// https://www.acmicpc.net/problem/2609

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void){
    FASTIO
    int n, m;
    std::cin >> n >> m;
    if(n < m) std::swap(n, m);
    
    int r1 = gcd(n, m);
    int r2 = n * m / r1;
    std::cout << r1 << '\n' << r2 << '\n';

    return 0;
}