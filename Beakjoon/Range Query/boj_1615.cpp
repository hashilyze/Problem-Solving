// Beakjoon 1615번 - 교차개수세기
// https://www.acmicpc.net/problem/1615

#include <iostream>
#include <algorithm>

// macro
#define FASTIO std::ios::sync_with_stdio(NULL); std::cin.tie(NULL), std::cout.tie(NULL);
// types
using ll = long long;
using pii = std::pair<int ,int>;
// constants
constexpr int MAX_N = 2'000;
// variables
int n, m;
int fenwick[MAX_N + 1];
pii edges[MAX_N * (MAX_N - 1) / 2];


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

    std::cin >> n >> m;
    for(int i = 0; i < m; ++i){
        std::cin >> edges[i].first >> edges[i].second;
    }
    std::sort(edges, edges + m);
    
    ll sum = 0;
    for(int i = 0; i < m; ++i){
        int a, b;
        std::tie(a, b) = edges[i];

        sum += (ll)queryFenwick(n) - queryFenwick(b);
        updateFenwick(b, 1);
    }
    std::cout << sum << '\n';

    return 0;
}