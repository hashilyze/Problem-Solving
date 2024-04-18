// Beakjoon 2942번 - 퍼거슨과 사과
// https://www.acmicpc.net/problem/2942

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(void){
    FASTIO

    int r, g;
    std::cin >> r >> g;
    int d = (r >= g ? gcd(r, g) : gcd(g, r));
    
    for(int i = 1; i * i <= d; ++i){
        if(d % i == 0){
            std::cout << i << " " << r / i << " " << g / i << "\n";
            if(i * i != d){
                int e = d / i;
                std::cout << e << " " << r / e << " " << g / e << "\n";
            }
        }
    }

    return 0;
}