// Beakjoon 12899번 - 데이터 구조

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
//types
using ll = long long;
// constants
constexpr int MAX_X = 2'000'000;
// variables
int segment[MAX_X << 2];

int kthElement(int kth, int nodeL, int nodeR, int node){
    if(nodeL == nodeR) return nodeL;
    int leftSum = segment[node * 2 + 1];
    int mid = (nodeL + nodeR) >> 1;
    if(kth < leftSum) return kthElement(kth, nodeL, mid, node * 2 + 1);
    else return kthElement(kth - leftSum, mid + 1, nodeR, node * 2 + 2);
}
void updateSegment(int pos, int diff, int nodeL, int nodeR, int node){
    segment[node] += diff;
    if(nodeL != nodeR){
        int mid = (nodeL + nodeR) >> 1;
        if(pos <= mid) updateSegment(pos, diff, nodeL, mid, node * 2 + 1);
        else updateSegment(pos, diff, mid + 1, nodeR, node * 2 + 2);
    }
}


int main(void){
    FASTIO
    int n;
    std::cin >> n;
    while(n--){
        int t, x;
        std::cin >> t >> x;
        switch(t){
        case 1:{
            updateSegment(x - 1, 1, 0, MAX_X - 1, 0);
        } break;
        case 2:{
            int target = kthElement(x - 1, 0, MAX_X - 1, 0);
            std::cout << target + 1 << '\n';
            updateSegment(target, -1, 0, MAX_X - 1, 0);
        } break;
        }
    }

    return 0;
}