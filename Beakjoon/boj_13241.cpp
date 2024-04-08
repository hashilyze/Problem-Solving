// Beakjoon 13241번 - 최소공배수
// https://www.acmicpc.net/problem/13241

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
    int n, m;
    std::cin >> n >> m;
    if(n < m) std::swap(n, m);
    std::cout << n * (m / gcd(n, m)) << '\n';

    return 0;
}