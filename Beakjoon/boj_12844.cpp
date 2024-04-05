// Beakjoon 12844번 - XOR
// https://www.acmicpc.net/problem/12844

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 500'000 + 10;
// variables
int n, m;
int arr[MAX_N];
int segment[MAX_N << 2];
int lazy[MAX_N << 2];


inline void updateLazy(int nodeL, int nodeR, int node){
    if(lazy[node]){
        if((nodeR - nodeL + 1) % 2) segment[node] ^= lazy[node];
        if(nodeL != nodeR){
            lazy[node * 2 + 1] ^= lazy[node];
            lazy[node * 2 + 2] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

int initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return segment[node] = arr[nodeL];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = initSegment(nodeL, mid, node * 2 + 1);
    int rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs ^ rhs;
}
int querySegment(int left, int right, int nodeL, int nodeR, int node){
    updateLazy(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return 0;
    if(left <= nodeL && nodeR <= right) return segment[node];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    int rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return lhs ^ rhs;
}
int updateSegment(int left, int right, int k, int nodeL, int nodeR, int node){
    updateLazy(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return segment[node];
    if(left <= nodeL && nodeR <= right){
        lazy[node] ^= k;
        updateLazy(nodeL, nodeR, node);
        return segment[node];
    }
    int mid = (nodeL + nodeR) >> 1;
    int lhs = updateSegment(left, right, k, nodeL, mid, node * 2 + 1);
    int rhs = updateSegment(left, right, k, mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs ^ rhs;
}


int main(void){
    FASTIO
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    initSegment(0, n - 1, 0);
    std::cin >> m;
    while(m--){
        int o, i, j, k;
        std::cin >> o;
        if(o == 1){ // xor
            std::cin >> i >> j >> k;
            updateSegment(i, j, k, 0, n - 1, 0);
        } else{     // query
            std::cin >> i >> j;
            std::cout << querySegment(i, j, 0, n - 1, 0) << '\n';
        }
        
    }

    return 0;
}