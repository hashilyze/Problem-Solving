// Beakjoon 10868번 - 최솟값

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

// constants
constexpr int MAX_N = 100'000 + 10;
constexpr int MAX_INT = 1'000'000'000;
// variables
int arr[MAX_N];
int segment[MAX_N << 2];
int n, m;
// functions
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


int main(void){
    FASTIO
    std::cin >> n >> m;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    initSegment(0, n - 1, 0);
    for(int i = 0; i < m; ++i){
        int a, b;
        std::cin >> a >> b;
        std::cout << querySegment(a - 1, b - 1, 0, n - 1, 0) << '\n';
    }
    return 0;
}