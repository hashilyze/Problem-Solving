#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// === File Control ====
const std::string FILE_NAME = "dish";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// types
using ll = long long;
// constants
constexpr int MAX_N = 500;
constexpr ll MOD = 1000000007LL;
// variabels
ll fact[MAX_N + 1];
ll dp[MAX_N + 1][MAX_N + 1];

// === mutiplicative inverse ===
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
ll inv_mul(ll i, ll n) { 
    ll a, b;
    xGCD(i, n, a, b);
    if(a < 0) a += n;
    return a;
}

// === combination ===
void initFact(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < MAX_N; ++i){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

ll comb(int n, int k){
    ll a = fact[n];
    ll b = (fact[k] * fact[n - k]) % MOD;
    ll invB = inv_mul(b, MOD);
    return (a * invB) % MOD;
}

ll R(int n, int k){
    ll &r = dp[n][k];
    if(r > 0) return r;

    if(n == k) return r = 1LL;
    if(k == 1) return r = fact[n - 1];

    r = 0LL;
    for(int i = k; i <= n; ++i){
        ll tmp = 1LL;
        tmp = (tmp * comb(n - 1, i - 1)) % MOD;
        tmp = (tmp * R(i - 1, k - 1)) % MOD;
        tmp = (tmp * fact[n - i]) % MOD;
        r = (r + tmp) % MOD;
    }
    return r;
}
int main(void){
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    int t;
    in >> t;
    initFact();
    while(t--){
        int n, k;
        in >> n >> k;
        out << n << " " << k << " " << R(n, k) << '\n';
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}