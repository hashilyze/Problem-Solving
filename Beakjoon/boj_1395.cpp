// Beakjoon 1395번 - 스위치
// https://www.acmicpc.net/problem/1395

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100'000 + 10;
// variables
int n, m;
int segment[MAX_N << 2];
int lazy[MAX_N << 2];

inline void updateLazy(int nodeL, int nodeR, int node){
    if(lazy[node]){
        segment[node] = (nodeR - nodeL + 1) - segment[node];
        if(nodeL != nodeR){
            lazy[node * 2 + 1] ^= 1;
            lazy[node * 2 + 2] ^= 1;
        }
        lazy[node] = 0;
    }
}

int querySegment(int left, int right, int nodeL, int nodeR, int node){
    updateLazy(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return 0;
    if(left <= nodeL && nodeR <= right) return segment[node];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    int rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return lhs + rhs;
}
int updateSegment(int left, int right, int nodeL, int nodeR, int node){
    updateLazy(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return segment[node];
    if(left <= nodeL && nodeR <= right) {
        lazy[node] = 1;
        updateLazy(nodeL, nodeR, node);
        return segment[node];
    }
    int mid = (nodeL + nodeR) >> 1;
    int lhs = updateSegment(left, right, nodeL, mid, node * 2 + 1);
    int rhs = updateSegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs + rhs;
}


int main(void){
    FASTIO
    std::cin >> n >> m;
    while(m--){
        int o, s, t;
        std::cin >> o >> s >> t;
        if(o == 0){ // toggle
            updateSegment(s - 1, t - 1, 0, n - 1, 0);
        } else{     // count
            std::cout << querySegment(s - 1, t - 1, 0, n - 1, 0)  << '\n';
        }
    }

    return 0;
}