// Beakjoon 12837번 - 가계부 (Hard)
// https://www.acmicpc.net/problem/12837

#include <iostream>
// macro
#define FASTIO std::ios::sync_with_stdio(NULL); std::cin.tie(NULL), std::cout.tie(NULL);
// tpyes
using ll = long long;
// constants
constexpr int MAX_N = 1'000'000;
// variables
int n, m;
ll fenwick[MAX_N + 1];


inline int getLastBit(int i) { return i & -i; }

ll queryFenwick(int pos){
    ll sum = 0LL;
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

    std::cin >> n >> m;
    while(m--){
        int a, b, c;
        std::cin >> a >> b >> c;
        switch(a){
        case 1:{
            updateFenwick(b, c);
        }break;
        case 2:{
            std::cout << queryFenwick(c) - queryFenwick(b - 1) << '\n';
        }break;
        }
    }

    return 0;
}