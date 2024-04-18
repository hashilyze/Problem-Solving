// Beakjoon 2243번 - 사탕 상자

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
//types
using ll = long long;
// constants
constexpr int MAX_LEVEL = 1'000'000;
constexpr int MAX_SIZE = MAX_LEVEL + 10;
// variables
int n;
int segment[MAX_SIZE << 2];

int kthElement(int kth, int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return nodeL;

    int mid = (nodeL + nodeR) >> 1;
    int leftSum = segment[node * 2 + 1];
    if(kth < leftSum){
        return kthElement(kth, nodeL, mid, node * 2 + 1);
    } else{
        return kthElement(kth - leftSum, mid + 1, nodeR, node * 2 + 2);
    }
}

void updateSegment(int pos, int diff, int nodeL, int nodeR, int node){
    segment[node] += diff;
    if(nodeL == nodeR) return;
    int mid = (nodeL + nodeR) >> 1;
    if(pos <= mid) updateSegment(pos, diff, nodeL, mid, node * 2 + 1);
    else updateSegment(pos, diff, mid + 1, nodeR, node * 2 + 2);
}

int main(void){
    FASTIO

    std::cin >> n;
    while(n--){
        int a, b, c;
        std::cin >> a;
        switch(a){
        case 1:{
            std::cin >> b;
            int target = kthElement(b - 1, 0, MAX_LEVEL - 1, 0);
            std::cout << target + 1 << '\n';
            updateSegment(target, -1, 0, MAX_LEVEL - 1, 0);
        } break;
        case 2:{
            std::cin >> b >> c;
            updateSegment(b - 1, c, 0, MAX_LEVEL - 1, 0);
        } break;
        }
    }

    return 0;
}