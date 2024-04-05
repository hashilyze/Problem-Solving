// Beakjoon 13925번 - 수열과 쿼리 13
// https://www.acmicpc.net/problem/13925

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
constexpr ll MOD = 1'000'000'000LL + 7;
constexpr int MAX_N = 100'000 + 10;
// variables
int n, m;
int arr[MAX_N];
int segment[MAX_N << 2];
int lazyAdd[MAX_N << 2];
int lazyMul[MAX_N << 2];


void propagateLazy(int nodeL, int nodeR, int node){
    if(lazyAdd[node] != 0 || lazyMul[node] != 1){
        segment[node] = (segment[node] * (ll)lazyMul[node]) % MOD;
        segment[node] = (segment[node] + (ll)(nodeR - nodeL + 1) * lazyAdd[node]) % MOD;
        if(nodeL != nodeR){
            for(int s = node * 2 + 1, e = s + 1; s <= e; ++s){
                lazyAdd[s] = ((ll)lazyAdd[s] * lazyMul[node] + lazyAdd[node]) % MOD;
                lazyMul[s] = ((ll)lazyMul[s] * lazyMul[node]) % MOD;
            }
        }
    }
    lazyAdd[node] = 0;
    lazyMul[node] = 1;
}

int initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return segment[node] = arr[nodeL];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = initSegment(nodeL, mid, node * 2 + 1);
    int rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    return segment[node] = (lhs + rhs) % MOD;
}

int querySegment(int left, int right, int nodeL, int nodeR, int node){
    propagateLazy(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return 0;
    if(left <= nodeL && nodeR <= right) return segment[node];
    int mid = (nodeL + nodeR) >> 1;
    int lhs = querySegment(left, right, nodeL, mid, node * 2 + 1);
    int rhs = querySegment(left, right, mid + 1, nodeR, node * 2 + 2);
    return (lhs + rhs) % MOD;
}

int updateSegment(int left, int right, int op, int val, int nodeL, int nodeR, int node){
    propagateLazy(nodeL, nodeR, node);
    if(right < nodeL || nodeR < left) return segment[node];
    if(left <= nodeL && nodeR <= right){
        if(op == 1) { lazyAdd[node] = val; lazyMul[node] = 1; }
        else if(op == 2) { lazyAdd[node] = 0; lazyMul[node] = val; }
        else { lazyAdd[node] = val; lazyMul[node] = 0; }

        propagateLazy(nodeL, nodeR, node);
        return segment[node];
    }
    int mid = (nodeL + nodeR) >> 1;
    int lhs = updateSegment(left, right, op, val, nodeL, mid, node * 2 + 1);
    int rhs = updateSegment(left, right, op, val, mid + 1, nodeR, node * 2 + 2);
    return segment[node] = (lhs + rhs) % MOD;
}


int main(void){
    FASTIO
    std::cin >> n;
    for(int i = 0; i < n; ++i) std::cin >> arr[i];
    for(int i = 0; i < n * 4; ++i) lazyMul[i] = 1;
    initSegment(0, n - 1, 0);

    std::cin >> m;
    while(m--){
        int o, x, y, v;
        std::cin >> o >> x >> y;

        if(o == 4){
            std::cout << querySegment(x - 1, y - 1, 0, n - 1, 0) << '\n';
        } else{
            std::cin >> v;
            updateSegment(x - 1, y - 1, o, v, 0, n - 1, 0);
        }
    }

    return 0;
}