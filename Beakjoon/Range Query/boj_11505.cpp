// Beakjoon 11505번 - 구간 곱 구하기

#include <iostream>

#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

// const
constexpr int MAX_N = 1'000'000 + 10;
constexpr int MOD = 1'000'000'007;
// variable
int arr[MAX_N] = { 0, };
int segment[MAX_N << 2] = { 0, };
int n, m, k;
// function

int initSegment(int nodeL, int nodeR, int index){
    if(nodeL == nodeR) return segment[index] = arr[nodeL];

    int mid = (nodeL + nodeR) >> 1;
    int lhs = initSegment(nodeL, mid, index * 2);
    int rhs = initSegment(mid + 1, nodeR, index * 2 + 1);
    return segment[index] = ((long long)lhs * rhs) % MOD;
}
int querySegment(int left, int right, int nodeL, int nodeR, int index){
    if(right < nodeL || nodeR < left) return 1LL;
    if(left <= nodeL && nodeR <= right) return segment[index];

    int mid = (nodeL + nodeR) >> 1;
    int lhs = querySegment(left, right, nodeL, mid, index * 2);
    int rhs = querySegment(left, right, mid + 1, nodeR, index * 2 + 1);
    return ((long long)lhs * rhs) % MOD;
}
int updateSegment(int pos, int val, int nodeL, int nodeR, int index){
    if(pos < nodeL || nodeR < pos) return segment[index];
    if(nodeL == nodeR && nodeL == pos) return segment[index] = arr[pos] = val % MOD;

    int mid = (nodeL + nodeR) >> 1;
    int lhs = updateSegment(pos, val, nodeL, mid, index * 2);
    int rhs = updateSegment(pos, val, mid + 1, nodeR, index * 2 + 1);
    return segment[index] = ((long long)lhs * rhs) % MOD;
}


int main(void){
    FASTIO
    std::cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i) {
        std::cin >> arr[i];
        arr[i] %= MOD;
    }
    initSegment(1, n, 1);

    for(int i = 0, e = m + k; i < e; ++i){
        int a, b, c;
        std::cin >> a >> b >> c;
        switch(a){ // update
        case 1:{
            updateSegment(b, c, 1, n, 1);
        } break;
        case 2:{ // sub sum
            std::cout << querySegment(b, c, 1, n, 1) << '\n';
        } break;
        }
    }

    return 0;
}