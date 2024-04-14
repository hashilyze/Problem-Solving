// Beakjoon 6064번 - 카잉 달력
// https://www.acmicpc.net/problem/6064

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_SIZE = 2;
// variables
int num[MAX_SIZE];
int rem[MAX_SIZE];

inline void shiftLeft(int& a, int& b, int c) { a = b; b = c; }

int xGCD(int a, int b, int& s, int& t){
    bool swap = a < b;
    if(swap) std::swap(a, b);

    int r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
    while(r2 > 0){
        int q = r1 / r2;
        shiftLeft(r1, r2, r1 - q * r2);
        shiftLeft(s1, s2, s1 - q * s2);
        shiftLeft(t1, t2, t1 - q * t2);
    }

    s = s1; t = t1;
    if(swap) std::swap(s, t);
    return r1;
}

int invAdd(int i, int n) { return n - i % n; }
int invMul(int i, int n) { 
    int s, t, gcdv = xGCD(i % n, n, s, t);
    if(gcdv == 1) return s;
    return -1;
}

int crt(int k){
    int n1 = num[0], r1 = rem[0];
    for(int i = 1; i < k; ++i){
        int n2 = num[i], r2 = rem[i];
        r2 = (r2 + invAdd(r1, n2)) % n2; // additive inverse
        
        int s, t, gcdv = xGCD(n1, n2, s, t); // multiplicative inverse
        if(r2 % gcdv != 0) return -1;
        n2 /= gcdv; r2 /= gcdv;

        if(s < 0) s += n2;
        r2 = (r2 * s) % n2;
        
        r1 = r1 + n1 * r2;
        n1 = n1 * n2;
    }
    return r1;
}



int solution(int m, int n, int x, int y){
    num[0] = m; num[1] = n;
    rem[0] = x - 1; rem[1] = y - 1;
    int crtv = crt(2);
    return crtv < 0 ? -1 : crtv + 1;
}

int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        int m, n, x, y;
        std::cin >> m >> n >> x >> y;
        std::cout << solution(m, n, x, y) << '\n';
    }

    return 0;
}