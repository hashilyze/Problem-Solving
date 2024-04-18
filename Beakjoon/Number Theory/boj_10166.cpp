// Beakjoon 10166번 - 관중석
// https://www.acmicpc.net/problem/10166

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 2'000;
// variables
int counts[MAX_N];


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(void){
    FASTIO

    int d1, d2;
    std::cin >> d1 >> d2;

    for(int i = 1; i <= d2; ++i){       // divisor
        int cnt = 0;
        for(int j = 0; j < i; ++j){     // dividend
            if(gcd(i, j) == 1) ++cnt;
        }
        counts[i - 1] = cnt;
    }

    int count = 0;
    for(int i = 1; i < d1; ++i){
        int j = (d1 / i) * i + (d1 % i ? i : 0);
        if(j <= d2){
            counts[j - 1] += counts[i - 1];
        }
    }
    for(int i = d1; i <= d2; ++i){
        count += counts[i - 1];
    }

    std::cout << count << '\n';

    return 0;
}