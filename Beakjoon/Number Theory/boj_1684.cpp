// Beakjoon 1684번 - 같은 나머지
// https://www.acmicpc.net/problem/1684

#include <iostream>
#include <algorithm>

// macro
#define FASTIO std::ios::sync_with_stdio(NULL); std::cin.tie(NULL), std::cout.tie(NULL);
// constants
constexpr int MAX_N = 1'000;
// variables
int n;
int num[MAX_N];

int gcd(int a, int b){
    if(a < b) std::swap(a, b);
    while(b > 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main(void){
    FASTIO

    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> num[i];
    std::sort(num, num + n);
    for(int i = 1; i < n; ++i) num[i - 1] = num[i] - num[i - 1];
    
    int gcdv = num[0];
    for(int i = 1; i < n - 1; ++i) gcdv = gcd(gcdv, num[i]);

    std::cout << gcdv << '\n';

    return 0;
}
