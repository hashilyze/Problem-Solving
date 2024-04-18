// Beakjoon 23062번 - 백남이의 여행 준비의 준비
// https://www.acmicpc.net/problem/23062

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr int MAX_SIZE = 3;
// variables
int num[MAX_SIZE];
int rem[MAX_SIZE];

inline void shiftLeft(ll& a, ll& b, ll c) { a = b; b = c; }

ll xGCD(ll a, ll b, ll& s, ll& t){
    bool isSwap = a < b;
    if(isSwap) std::swap(a, b);
    ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;

    while(r2 > 0){
        ll q = r1 / r2;
        shiftLeft(r1, r2, r1 - q * r2);
        shiftLeft(s1, s2, s1 - q * s2);
        shiftLeft(t1, t2, t1 - q * t2);
    }

    s = s1; t = t1;
    if(isSwap) std::swap(s, t);
    return r1;
}

inline ll invAdd(ll i, ll n) { return n - i % n; }

ll crt(int k){
    ll n1 = num[0], r1 = rem[0];
    for(int i = 1; i < k; ++i){
        ll n2 = num[i], r2 = rem[i];
        r2 = (r2 + invAdd(r1, n2)) % n2;

        ll s, t, gcdv = xGCD(n1, n2, s, t);
        if(r2 % gcdv != 0) return -1;
        n2 /= gcdv; r2 /= gcdv;
        
        if(s < 0) s += n2;
        r2 = (r2 * s) % n2;

        r1 = r1 + n1 * r2;
        n1 = n1 * n2;
    }
    return r1;
}


int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        for(int i = 0; i < MAX_SIZE; ++i) std::cin >> num[i];
        for(int i = 0; i < MAX_SIZE; ++i) std::cin >> rem[i];
        std::cout << crt(MAX_SIZE) << '\n';
    }

    return 0;
}