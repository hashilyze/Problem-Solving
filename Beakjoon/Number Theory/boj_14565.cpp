// Beakjoon 14565번 - 역원 구하기
// https://www.acmicpc.net/problem/14565

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;

ll extendedGcd(ll r1, ll r2, ll& a, ll& b){
    ll s1 = 1, s2 = 0, t1 = 0, t2 = 1;
    while(r2 > 0){
        ll q = r1 / r2;

        ll r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        ll s = s1 - q * s2;
        s1 = s2;
        s2 = s;

        ll t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    a = s1;
    b = t1;
    return r1;
}

ll inverseAdd(ll i, ll n){ return (n - i) % n; }
ll inverseMul(ll i, ll n){
    ll a, b;
    ll gcdv = extendedGcd(n, i, a, b);
    return (gcdv == 1 ? (b + n) % n : -1);
}

int main(void){
    FASTIO

    ll n, a;
    std::cin >> n >> a;
    std::cout << inverseAdd(a, n) << " " << inverseMul(a, n) << '\n';

    return 0;
}