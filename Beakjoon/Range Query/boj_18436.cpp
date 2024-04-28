// Beakjoon 18436번 - 수열과 쿼리 37
// https://www.acmicpc.net/problem/18436

#include <iostream>


// macro
#define FASTIO std::ios::sync_with_stdio(NULL); std::cin.tie(NULL), std::cout.tie(NULL);
// constants
constexpr int MAX_N = 10;
// variables
int n;
int arr[MAX_N];
int segment[MAX_N << 2];


int initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return segment[node] = arr[nodeL] % 2;
    int mid = (nodeL + nodeR) >> 1;
    int lhs = initSegment(nodeL, mid, node * 2 + 1);
    int rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs + rhs;
}

int querySegment(int left, int right, int nodeL, int nodeR, int node){
    if(right < nodeL || nodeR < left) return 0;
    if(left <= nodeL && nodeR <= right) return segment[node];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    int rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return lhs + rhs;
}

int updateSegment(int pos, int val, int nodeL, int nodeR, int node){
    if(pos < nodeL || nodeR < pos) return segment[node];
    if(nodeL == nodeR && nodeL == pos) return segment[node] = (arr[pos] = val) % 2;
    int mid = (nodeL + nodeR) >> 1;
    int lhs = updateSegment(pos, val, nodeL, mid, node * 2 + 1);
    int rhs = updateSegment(pos, val, mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs + rhs;
}


int main(void){
    FASTIO

    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    initSegment(0, n - 1, 0);

    int m;

    std::cin >> m;
    while(m--){
        int a, b, c;
        std::cin >> a >> b >> c;
        switch(a){
        case 1:{
            updateSegment(b - 1, c, 0, n - 1, 0);
        }break;
        case 2:{
            std::cout << (c - b + 1) - querySegment(b - 1, c - 1, 0, n - 1, 0) << '\n';
        }break;
        case 3:{
            std::cout << querySegment(b - 1, c - 1, 0, n - 1, 0) << '\n';
        }break;
        }
    }

    return 0;
}