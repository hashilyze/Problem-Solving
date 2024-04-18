// Beakjoon 3036번 - 링
// https://www.acmicpc.net/problem/3036

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// tpyes
using ll = long long;

ll gcd(ll a, ll b){
    if(a < b) std::swap(a, b);
    while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main(void){
    FASTIO

    int n;
    int f, s;
    std::cin >> n >> f;
    for(int i = 1; i < n; ++i){
        std::cin >> s;
        int d = gcd(f, s);
        std::cout << f / d << "/" << s / d << "\n";
    }
    

    return 0;
}