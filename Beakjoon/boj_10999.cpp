// Beakjoon 10999번 - 구간 합 구하기 2

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// type
using ll = long long;
// constants
constexpr int MAX_N = 1'000'000 + 10;
// variables
ll arr[MAX_N];
ll segment[MAX_N << 2];
ll lazy[MAX_N << 2];
int n, m, k;
// functions
ll initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return segment[node] = arr[nodeL];
    int mid = (nodeL + nodeR) >> 1;
    ll lhs = initSegment(nodeL, mid, node * 2 + 1);
    ll rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs + rhs;
}
void lazyPropagate(int nodeL, int nodeR, int node){
    if(lazy[node]){
        segment[node] += lazy[node] * (nodeR - nodeL + 1);
        if(nodeL != nodeR){
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
}
ll querySegment(int left, int right, int nodeL, int nodeR, int node){
    lazyPropagate(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return 0LL;
    if(left <= nodeL && nodeR <= right) return segment[node];

    int mid = (nodeL + nodeR) >> 1;
    ll lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    ll rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return lhs + rhs;
}
ll updateRangeSegment(int left, int right, ll diff, int nodeL, int nodeR, int node){
    lazyPropagate(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return segment[node];
    if(left <= nodeL && nodeR <= right) {
        lazy[node] += diff;
        lazyPropagate(nodeL, nodeR, node);
        return segment[node];
    }

    int mid = (nodeL + nodeR) >> 1;
    ll lhs = updateRangeSegment(left, right, diff, nodeL, mid, node * 2 + 1);
    ll rhs = updateRangeSegment(left, right, diff, mid + 1, nodeR, node * 2 + 2);
    return segment[node] = lhs + rhs;
}


int main(void){
    FASTIO
    std::cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    initSegment(0, n - 1, 0);

    for(int i = 0; i < m + k; ++i){
        int a;
        std::cin >> a;

        switch(a){
        case 1:{
            int b, c;
            ll d;
            std::cin >> b >> c >> d;
            updateRangeSegment(b - 1, c - 1, d, 0, n - 1, 0);
        } break;
        case 2:{
            int b, c;
            std::cin >> b >> c;
            std::cout << querySegment(b - 1, c - 1, 0, n - 1, 0) << '\n';
        } break;
        }
    }
    return 0;
}