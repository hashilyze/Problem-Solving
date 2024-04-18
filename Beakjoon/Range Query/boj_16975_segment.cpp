// Beakjoon 16975번 - 수열과 쿼리 21 (segment)

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// type
using ll = long long;
//constants
constexpr int MAX_N = 100'0000;
// variables
int n, m;
ll arr[MAX_N];
ll segments[MAX_N << 2];
ll lazy[MAX_N << 2];
// functions
ll initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return segments[node] = arr[nodeL];
    int mid = (nodeL + nodeR) >> 1;
    ll lhs = initSegment(nodeL, mid, node * 2 + 1);
    ll rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    return segments[node] = lhs + rhs;
}
void lazyPropagate(int nodeL, int nodeR, int node){
    if(lazy[node]){
        segments[node] += lazy[node] * (nodeR - nodeL + 1);
        if(nodeL != nodeR){
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
}
ll querySegment(int left, int right, int nodeL, int nodeR, int node){
    lazyPropagate(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return 0;
    if(left <= nodeL && nodeR <= right) return segments[node];
    int mid = (nodeL + nodeR) >> 1;
    ll lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    ll rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return lhs + rhs;
}
ll updateSegment(int left, int right, ll diff, int nodeL, int nodeR, int node){
    lazyPropagate(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return segments[node];
    if(left <= nodeL && nodeR <= right){
        lazy[node] += diff;
        lazyPropagate(nodeL, nodeR, node);
        return segments[node];
    }
    int mid = (nodeL + nodeR) >> 1;
    ll lhs = updateSegment(left, right, diff, nodeL, mid, node * 2 + 1);
    ll rhs = updateSegment(left, right, diff, mid + 1, nodeR, node * 2 + 2);
    return segments[node] = lhs + rhs;
}


int main(void){
    FASTIO
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    initSegment(0, n - 1, 0);

    std::cin >> m;
    while(m--){
        int option;
        std::cin >> option;
        switch(option){
        case 1:{
            int i, j;
            ll k;
            std::cin >> i >> j >> k;
            updateSegment(i - 1, j - 1, k, 0, n - 1, 0);
        } break;
        case 2:{
            int x;
            std::cin >> x;
            std::cout << querySegment(x - 1, x - 1, 0, n - 1, 0) << '\n';
        } break;
        }
    }

    return 0;
}