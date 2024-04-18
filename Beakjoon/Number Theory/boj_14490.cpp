// Beakjoon 14490번 - 백대열
// https://www.acmicpc.net/problem/14490

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(void){
    FASTIO

    char sep;
    int n, m;
    std::cin >> n >> sep >> m;
    
    int d = (n >= m ? gcd(n, m) : gcd(m, n));
    std::cout << n / d << ':' << m / d << '\n';


    return 0;
}