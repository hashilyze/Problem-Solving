// Beakjoon 14428번 - 수열과 쿼리 16
// https://www.acmicpc.net/problem/14428

#include <iostream>


// macro
#define FASTIO std::ios::sync_with_stdio(NULL); std::cin.tie(NULL), std::cout.tie(NULL);
// types
using pii = std::pair<int ,int>;
// constants
constexpr int MAX_N = 100'000;
// variables
int n, m;
int arr[MAX_N];
pii segment[MAX_N << 2];


pii initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return segment[node] = { arr[nodeL], nodeL };
    int mid = (nodeL + nodeR) >> 1;
    pii lhs = initSegment(nodeL, mid, node * 2 + 1);
    pii rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    return segment[node] = std::min(lhs, rhs);
}
pii querySegment(int left, int right, int nodeL, int nodeR, int node){
    if(right < nodeL || nodeR < left) return { 2147483647, 2147483647 };
    if(left <= nodeL && nodeR <= right) return segment[node];

    int mid = (nodeL + nodeR) >> 1;
    pii lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    pii rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return std::min(lhs, rhs);
}
pii updateSegment(int pos, int val, int nodeL, int nodeR, int node){
    if(pos < nodeL || nodeR < pos) return segment[node];
    if(nodeL == nodeR && nodeL == pos) return segment[node] = { arr[pos] = val, pos };
    int mid = (nodeL + nodeR) >> 1;
    pii lhs = updateSegment(pos, val, nodeL, mid, node * 2 + 1);
    pii rhs = updateSegment(pos, val, mid + 1, nodeR, node * 2 + 2);
    return segment[node] = std::min(lhs, rhs);
}


int main(void){
    FASTIO

    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    initSegment(0, n - 1, 0);


    std::cin >> m;
    for(int i = 0; i < m; ++i){
        int a, b, c;
        std::cin >> a >> b >> c;
        switch(a){
        case 1:{ // update
            updateSegment(b - 1, c, 0, n - 1, 0);
        }break;
        case 2:{ // query
            std::cout << querySegment(b - 1, c - 1, 0, n - 1, 0).second + 1 << '\n';
        }break;
        }
    }

    return 0;
}