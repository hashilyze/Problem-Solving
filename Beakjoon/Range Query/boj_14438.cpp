// Beakjoon 14438번 - 수열과 쿼리 17
// https://www.acmicpc.net/problem/14438

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// tpyes
using ll = long long;
// constants
constexpr int MAX_N = 100'000 + 10;
constexpr int MAX_INT = 1'000'000'000;
// variables
int n, m;
int arr[MAX_N];
int segment[MAX_N << 2];

int initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return segment[node] = arr[nodeL];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = initSegment(nodeL, mid, node * 2 + 1);
    int rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    return segment[node] = std::min(lhs, rhs);
}
int querySegment(int left, int right, int nodeL, int nodeR, int node){
    if(right < nodeL || nodeR < left) return MAX_INT;
    if(left <= nodeL && nodeR <= right) return segment[node];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    int rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return std::min(lhs, rhs);
}
int updateSegment(int pos, int val, int nodeL, int nodeR, int node){
    if(pos < nodeL || nodeR < pos) return segment[node];
    if(nodeL == nodeR && nodeL == pos) return segment[node] = arr[pos] = val;
    int mid = (nodeL + nodeR) >> 1;
    int lhs = updateSegment(pos, val, nodeL, mid, node * 2 + 1);
    int rhs = updateSegment(pos, val, mid + 1, nodeR, node * 2 + 2);
    return segment[node] = std::min(lhs, rhs);
}


int main(void){
    FASTIO
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    initSegment(0, n - 1, 0);

    std::cin >> m;
    while(m--){
        int option, i, j;
        std::cin >> option >> i >> j;
        if(option == 1){
            updateSegment(i - 1, j, 0, n - 1, 0);
        } else{
            std::cout << querySegment(i - 1, j - 1, 0, n - 1, 0) << '\n';
        }
    }

    return 0;
}