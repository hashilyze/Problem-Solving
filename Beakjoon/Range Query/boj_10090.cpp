// Beakjoon 10090번 - Counting Inversions
// https://www.acmicpc.net/problem/10090

#include <iostream>
// macro
#define FASTIO std::ios::sync_with_stdio(NULL); std::cin.tie(NULL), std::cout.tie(NULL);
// tpyes
using ll = long long;
// constants
constexpr int MAX_N = 1'000'000;
// variables
int n;
int fenwick[MAX_N + 1];


inline int getLastBit(int i) { return i & -i; }
int queryFenwick(int pos){
    int sum = 0;
    while(pos > 0){
        sum += fenwick[pos];
        pos -= getLastBit(pos);
    }
    return sum;
}
void updateFenwick(int pos, int diff){
    while(pos <= n){
        fenwick[pos] += diff;
        pos += getLastBit(pos);
    }
}


int main(void){
    FASTIO

    std::cin >> n;

    ll sum = 0LL;
    for(int i = 1; i <= n; ++i){
        int j;
        std::cin >> j;
        
        updateFenwick(j, 1);
        sum += i - queryFenwick(j);
    }
    std::cout << sum << '\n';


    return 0;
}