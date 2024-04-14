// 문제해결 기법 과제-14
#include <iostream>
#include <fstream>
#include <string>
// === File Control ====
const std::string FILE_NAME = "crt";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// types
using ll = long long;
// constants
constexpr ll MAX_N = 50;
// variables
ll num[MAX_N];
ll rem[MAX_N];

inline void shiftLeft(ll& a, ll& b, ll c) { a = b; b = c; }

ll xGCD(ll a, ll b, ll& s, ll& t){
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
    ll n1 = num[0], r1 = rem[0];                // x = r1 (mod n1); x = n1*s + r1
    for(ll i = 1; i < k; ++i){
        ll n2 = num[i], r2 = rem[i];            // n1*s + r1 = r2 (mod n2)
        ll r = (r2 + invAdd(r1, n2)) % n2;      // n1*s = (r2 + -r1) (mod n2); n1*s = r (mode n2)

        ll s, t, gcdv = xGCD(n1, n2, s, t);
        if(r % gcdv != 0) return -1;
        n2 /= gcdv; r /= gcdv;
        if(s < 0) s+= n2;
        r = (r * s) % n2;                       // s = r * n1^-1 (mod n2); s = r' (mod n2); s = n2*t + r'

        r1 = n1 * r + r1;                       // x = (n1 * n2) * t + (n1 * r' + r1)
        n1 = n1 * n2;
    }
    return r1;
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
    while(t--){
        int k;
        in >> k;
        for(int i = 0; i < k; ++i) in >> rem[i] >> num[i];
        out << crt(k) << '\n';
    }

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}