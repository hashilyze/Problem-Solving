// Beakjoon 1850번 - 최대공약수
// https://www.acmicpc.net/problem/1850

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// tpyes
using ll = unsigned long long;

ll gcd(ll a, ll b){
    if(b == 0LL) return a;
    return gcd(b, a % b);
}

int main(void){
    FASTIO

    ll n, m;
    std::cin >> n >> m;
    if(n < m) std::swap(n, m);
    ll d = gcd(n, m);
    for(ll i = 0LL; i < d; ++i){
        std::cout << '1';
    }
    std::cout << '\n';

    return 0;
}