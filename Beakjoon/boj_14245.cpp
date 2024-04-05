// Beakjoon 14245번 - XOR
// https://www.acmicpc.net/problem/14245

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


inline void propagateLazy(int nodeL, int nodeR, int node){
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
    return segment[node] = initSegment(nodeL, mid, node * 2 + 1) 
        ^ initSegment(mid + 1, nodeR, node * 2 + 2);
}
int querySegment(int pos, int nodeL, int nodeR, int node){
    propagateLazy(nodeL, nodeR, node);
    if(pos < nodeL || nodeR < pos) return 0;
    if(nodeL == nodeR && nodeL == pos) return segment[node];
    int mid = (nodeL + nodeR) >> 1;
    return querySegment(pos, nodeL, mid, node * 2 + 1)
        ^ querySegment(pos, mid + 1, nodeR, node * 2 + 2);
}
int updateSegment(int left, int right, int val, int nodeL, int nodeR, int node){
    propagateLazy(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return segment[node];
    if(left <= nodeL && nodeR <= right) {
        lazy[node] = val;
        propagateLazy(nodeL, nodeR, node);
        return segment[node];
    }
    int mid = (nodeL + nodeR) >> 1;
    return segment[node] = updateSegment(left, right, val, nodeL, mid, node * 2 + 1)
        ^ updateSegment(left, right, val, mid + 1, nodeR, node * 2 + 2);
}




int main(void){
    FASTIO
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    initSegment(0, n - 1, 0);

    std::cin >> m;
    while(m--){
        int t, a, b, c;
        std::cin >> t;
        if(t == 1){ // xor
            std::cin >> a >> b >> c;
            updateSegment(a, b, c, 0, n - 1, 0);
        } else{ // query
            std::cin >> a;
            std::cout << querySegment(a, 0, n - 1, 0) << '\n';
        }
    }

    return 0;
}