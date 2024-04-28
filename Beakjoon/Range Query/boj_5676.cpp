// Beakjoon 5676번 - 음주 코딩
// https://www.acmicpc.net/problem/5676

#include <iostream>


// macro
#define FASTIO std::ios::sync_with_stdio(NULL); std::cin.tie(NULL), std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100'000;
// variables
int n, k;
int arr[MAX_N];
int segment[MAX_N << 2];


inline int sign(int i) { return (i == 0 ? 0 : (i < 0 ? -1 : 1)); }

int initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return segment[node] = sign(arr[nodeL]);
    int mid = (nodeL + nodeR) >> 1;
    int lhs = initSegment(nodeL, mid, node * 2 + 1);
    int rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs * rhs;
}

int querySegment(int left, int right, int nodeL, int nodeR, int node){
    if(right < nodeL || nodeR < left) return 1;
    if(left <= nodeL && nodeR <= right) return segment[node];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    int rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return lhs * rhs;
}

int updateSegment(int pos, int val, int nodeL, int nodeR, int node){
    if(pos < nodeL || nodeR < pos) return segment[node];
    if(nodeL == nodeR && nodeL == pos) return segment[node] = sign(arr[pos] = val);
    int mid = (nodeL + nodeR) >> 1;
    int lhs = updateSegment(pos, val, nodeL, mid, node * 2 + 1);
    int rhs = updateSegment(pos, val, mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs * rhs;
}


int main(void){
    FASTIO

    while(std::cin >> n >> k){
        for(int i = 0; i < n; ++i) std::cin >> arr[i];
        initSegment(0, n - 1, 0);

        while(k--){
            char a;
            int b, c;
            std::cin >> a >> b >> c;
            switch(a){
            case 'C':{
                updateSegment(b - 1, c, 0, n - 1, 0);
            }break;
            case 'P':{
                int ret = querySegment(b - 1, c - 1, 0, n - 1, 0);
                std::cout << (ret == 0 ? '0' : (ret < 0 ? '-' : '+'));
            }break;
            }
        }
        std::cout << '\n';
    }

    return 0;
}