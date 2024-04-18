// Beakjoon 12971번 - 숫자놀이
// https://www.acmicpc.net/problem/12971

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr ll MAX_N = 3;
// variables
ll num[MAX_N];
ll rem[MAX_N];

inline void shiftLeft(ll& a, ll& b, ll c) { a = b; b = c; }

ll exGCD(ll a, ll b, ll& s, ll& t){
    bool swap = a < b;
    if(swap) std::swap(a, b);

    ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
    while(r2 > 0){
        ll q = r1 / r2;
        shiftLeft(r1, r2, r1 - q * r2);
        shiftLeft(s1, s2, s1 - q * s2);
        shiftLeft(t1, t2, t1 - q * t2);
    }

    s = s1; t = t1;
    if(swap) std::swap(s, t);
    return r1;
}

inline ll invAdd(ll i, ll n) { return (n - i % n) % n; }

ll crt(ll k){
    ll n1 = num[0], r1 = rem[0];                // x = n1*s + r1
    for(ll i = 1; i < k; ++i){
        ll n2 = num[i], r2 = rem[i];            // n1*s + r1 = r2 (mod n2)
        ll r = (r2 + invAdd(r1, n2)) % n2;      // n1*s = (r2 + -r1) (mod n2)

        ll s, t, gcdv = exGCD(n1, n2, s, t);    // s = (r2 + -r1) * n1^-1 (mod n2)
        if(r % gcdv != 0) return -1;            // s = n2*t + (r2 + -r1) * n1^-1
        n2 /= gcdv; r /= gcdv;
        if(s < 0) s+= n2;
        r = (r * s) % n2;

        r1 = n1 * r + r1;
        n1 = n1 * n2;
    }
    if(r1 < 1'000'000'000) 
        return r1;
    return -1;
}



int main(void){
    FASTIO

    for(ll i = 0; i < MAX_N; ++i) std::cin >> num[i];
    for(ll i = 0; i < MAX_N; ++i) std::cin >> rem[i];
    
    std::cout << crt(MAX_N) << '\n';

    return 0;
}