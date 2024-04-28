// Beakjoon 7578번 - 공장
// https://www.acmicpc.net/problem/7578

#include <iostream>
// macro
#define FASTIO std::ios::sync_with_stdio(NULL); std::cin.tie(NULL), std::cout.tie(NULL);
// tpyes
using ll = long long;
// constants
constexpr int MAX_N = 500'000;
constexpr int MAX_INDEX = 1'000'000;
// variables
int n;
int fenwick[MAX_N + 1];
int indecis[MAX_INDEX + 1];


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

    for(int i = 0; i < n; ++i) {
        int index;
        std::cin >> index;
        indecis[index] = i + 1;
    }
    ll sum = 0LL;
    for(int i = 0; i < n; ++i){
        int index;
        std::cin >> index;
        
        //int a = i + 1;
        int b = indecis[index];
        sum += i - queryFenwick(b);
        updateFenwick(b, 1);
    }
    std::cout << sum << '\n';


    return 0;
}