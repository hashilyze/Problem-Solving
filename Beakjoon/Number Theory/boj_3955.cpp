// Beakjoon 3955번 - 캔디분배
// https://www.acmicpc.net/problem/3955

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;

inline void shiftLeft(ll& a, ll& b, ll c){ a = b; b = c; }

ll extendedGCD(ll r1, ll r2, ll& a, ll& b){
    bool swap = r1 < r2;
    if(swap) std::swap(r1, r2);

    ll s1 = 1, s2 = 0, t1 = 0, t2 = 1;
    while(r2 > 0){
        ll q = r1 / r2;
        shiftLeft(r1, r2, r1 - q * r2);
        shiftLeft(s1, s2, s1 - q * s2);
        shiftLeft(t1, t2, t1 - q * t2);
    }
    a = s1;
    b = t1;
    if(swap) std::swap(a, b);
    return r1;
}


int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        ll k, c;
        std::cin >> k >> c;
        
        
        ll a, b;
        ll gcdv = extendedGCD(k, c, a, b);
        if(gcdv == 1){
            while(b <= 0 || a >= 0){
                b += k;
                a -= c;
            }
            if(b <= 1'000'000'000){
                std::cout << b << '\n';
                continue;
            }
        }
        std::cout << "IMPOSSIBLE\n";
    }


    return 0;
}