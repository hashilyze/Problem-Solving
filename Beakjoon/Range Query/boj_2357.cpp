// Beakjoon 2357번 - 최솟값과 최댓값

#include <iostream>

#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

// const
constexpr int MAX_N = 100'000 + 10;
constexpr int MAX_INT = 1'000'000'000;
constexpr int MIN_INT = 1;
// variable
int arr[MAX_N] = { 0, };
int segmentMin[MAX_N << 2] = { 0, };
int segmentMax[MAX_N << 2] = { 0, };
int n, m;
// function

void initSegment(int nodeL, int nodeR, int index){ 
    if(nodeL == nodeR) {
        segmentMin[index] = segmentMax[index] = arr[nodeL];
        return;
    }
    
    int mid = (nodeL + nodeR) >> 1;
    initSegment(nodeL, mid, index * 2);
    initSegment(mid + 1, nodeR, index * 2 + 1);
    segmentMin[index] = std::min(segmentMin[index * 2], segmentMin[index * 2 + 1]);
    segmentMax[index] = std::max(segmentMax[index * 2], segmentMax[index * 2 + 1]);
}
std::pair<int, int> querySegment(int left, int right, int nodeL, int nodeR, int index){ 
    if(right < nodeL || nodeR < left) return { MAX_INT, MIN_INT };
    if(left <= nodeL && nodeR <= right) return { segmentMin[index], segmentMax[index] };

    int mid = (nodeL + nodeR) >> 1;
    auto lhs = querySegment(left, right, nodeL, mid, index * 2);
    auto rhs = querySegment(left, right, mid + 1, nodeR, index * 2 + 1);
    return {
        std::min(lhs.first, rhs.first), 
        std::max(lhs.second, rhs.second)
    };
}
std::pair<int, int> updateSegment(int pos, int val, int nodeL, int nodeR, int index) { 
    if(pos < nodeL || nodeR < pos) return { segmentMin[index], segmentMax[index] };
    if(nodeL == nodeR && nodeL == pos) return { segmentMin[index] = val, segmentMax[index] = val };

    int mid = (nodeL + nodeR) >> 1;
    auto lhs = updateSegment(pos, val, nodeL, mid, index * 2);
    auto rhs = updateSegment(pos, val, mid + 1, nodeR, index * 2 + 1);
    return {
        segmentMin[index] = std::min(lhs.first, rhs.first),
        segmentMax[index] = std::max(lhs.second, rhs.second),
    };
}


int main(void){
    FASTIO
    std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) std::cin >> arr[i];
    initSegment(1, n, 1);

    for(int i = 0; i < m; ++i){
        int a, b;
        std::cin >> a >> b;
        auto ret = querySegment(a, b, 1, n, 1);
        std::cout << ret.first << " " << ret.second << '\n';
    }

    return 0;
}