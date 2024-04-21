// Beakjoon 18132 - 내 이진트리를 돌려줘!!!
// https://www.acmicpc.net/problem/18132

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
//types
using ll = long long;
// constants
constexpr int MAX_N = 10'002;
constexpr ll MOD = 1'000'000'007LL;
// variables
ll fact[MAX_N];

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
ll invMul(ll i, ll n) { 
    ll a, b;
    xGCD(i, n, a, b);
    if(a < 0) a += n;
    return a;
}

void initFact(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= MAX_N; ++i){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
ll comb(int n, int k){
    ll a = fact[n];
    ll b = (fact[k] * fact[n - k]) % MOD;
    ll invB = invMul(b, MOD);
    return (a * invB) % MOD;
}

ll catalan(int n){
    ll r1 = comb(2 * n, n);
    ll r2 = invMul(n + 1, MOD);
    return (r1 * r2) % MOD;
}

int main(void){
    FASTIO
    initFact();
    
    int t;
    std::cin >> t;
    while(t--){
        int e;
        std::cin >> e;
        std::cout << catalan(e + 1) << '\n';
    }

    return 0;
}