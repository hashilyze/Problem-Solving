// Beakjoon 1168번 - 요세푸스 문제 2

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// constants
constexpr int MAX_N = 100'000 + 10;
// variables
int n, k;
std::pair<int, int> segment[MAX_N << 2];

int initSegment(int nodeL, int nodeR, int node){
    if(nodeL == nodeR) {
        segment[node] = { nodeL, 1 };
        return 1;
    }
    int mid = (nodeL + nodeR) >> 1;
    int lhs = initSegment(nodeL, mid, node * 2 + 1);
    int rhs = initSegment(mid + 1, nodeR, node * 2 + 2);
    segment[node] = { -1, lhs + rhs };
    return segment[node].second;
}
int kthElement(int kth, int nodeL, int nodeR, int node){
    segment[node].second -= 1;
    if(nodeL == nodeR) return segment[node].first;

    int mid = (nodeL + nodeR) >> 1;
    int leftSum = segment[node * 2 + 1].second;
    if(kth < leftSum) return kthElement(kth, nodeL, mid, node * 2 + 1);
    else return kthElement(kth - leftSum, mid + 1, nodeR, node * 2 + 2);
}


int main(void){
    FASTIO
    std::cin >> n >> k;
    initSegment(0, n - 1, 0);

    std::cout << "<";
    int next = 0;
    for(int i = 0; i < n; ++i){
        next = (next + k - 1) % (n - i);
        int target = kthElement(next, 0, n - 1, 0);
        std::cout << target + 1;
        if(i == n - 1) std::cout << ">\n";
        else std::cout << ", ";
    }

    return 0;
}