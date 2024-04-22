// Beakjoon 3392 - 화성 지도
// https://www.acmicpc.net/problem/3392

#include <iostream>
#include <algorithm>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;

struct Line {
    Line() = default;
    Line(int _x, int _y1, int _y2, int _op)
        : x(_x), y1(_y1), y2(_y2), op(_op) { }

    int x;
    int y1, y2;
    int op;
};

bool operator<(const Line& lhs, const Line& rhs) {
    if(lhs.x != rhs.x) return lhs.x < rhs.x;
    if(lhs.y1 != rhs.y1) return lhs.y1 < rhs.y1;
    if(lhs.y2 != rhs.y2) return lhs.y2 < rhs.y2;
    return lhs.op < rhs.op;
}

// constants
constexpr int MAX_N = 10'000;
constexpr int MAX_SIZE = 30'001;
// variables
int segment1[MAX_SIZE << 2];
int segment2[MAX_SIZE << 2];
Line lines[MAX_N << 1];


void updateSegment(int left, int right, int diff, int nodeL, int nodeR, int node){
    if(right < nodeL || nodeR < left) return;
    if(left <= nodeL && nodeR <= right) segment2[node] += diff;
    else {
        int mid = (nodeL + nodeR) >> 1;
        updateSegment(left, right, diff, nodeL, mid, node * 2 + 1);
        updateSegment(left, right, diff, mid + 1, nodeR, node * 2 + 2);
    }
    
    if(segment2[node]) segment1[node] = nodeR - nodeL + 1;
    else if(nodeL != nodeR) segment1[node] = segment1[node * 2 + 1] + segment1[node * 2 + 2];
    else segment1[node] = 0;
}


ll solution(int n){
    ll area = 0LL;

    int leftX = lines[0].x;
    for(int i = 0; i < n; ++i){
        const Line &line = lines[i];
        if(leftX != line.x){
            area += (ll)(line.x - leftX) * segment1[0];
            leftX = line.x;
        }
        updateSegment(line.y1, line.y2, -line.op, 0, MAX_SIZE - 1, 0);
    }
    return area;
}


int main(void){
    FASTIO
    
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        lines[2 * i] = { x1, y1, y2 - 1, -1 };
        lines[2 * i + 1] = { x2, y1, y2 - 1, 1 };
    }
    std::sort(lines, lines + n * 2);

    std::cout << solution(n * 2) << '\n';

    return 0;
}