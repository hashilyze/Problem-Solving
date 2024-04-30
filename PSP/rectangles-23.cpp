// 문제해결기법 과제-23

#include <iostream>
#include <fstream>
#include <algorithm>


// === File Control ====
const std::string FILE_NAME = "rectangles";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// types
using ll = long long;

struct Line {
    enum EOP { LEFT = -1, RIGHT = 1 };

    Line() = default;
    Line(int x, int y1, int y2, EOP op) : x(x), y1(y1), y2(y2), op(op) { }

    int x;
    int y1, y2;
    EOP op;
};
// constants
constexpr int MAX_N = 10000;
constexpr int MAX_SIZE = 20001;
// variables
int n;
int segment1[MAX_SIZE << 2];
int segment2[MAX_SIZE << 2];
Line lines[MAX_N << 1];


inline int coord2Index(int c) { return c + 10000; }


void updateSegment(int left, int right, int diff, int nodeL, int nodeR, int node){
    if(right < nodeL || nodeR < left) return;
    if(left <= nodeL && nodeR <= right) {
        segment2[node] += diff;
    } else{
        int mid = (nodeL + nodeR) >> 1;
        updateSegment(left, right, diff, nodeL, mid, node * 2 + 1);
        updateSegment(left, right, diff, mid + 1, nodeR, node * 2 + 2);
    }
    if(segment2[node]) segment1[node] = nodeR - nodeL + 1;
    else if(nodeL != nodeR) segment1[node] = segment1[node * 2 + 1] + segment1[node * 2 + 2];
    else segment1[node] = 0;
}

ll solution(){
    std::sort(lines, lines + 2 * n, [](const Line& lhs, const Line& rhs) {
        if(lhs.x != rhs.x) return lhs.x < rhs.x;
        if(lhs.y1 != rhs.y1) return lhs.y1 < rhs.y1;
        if(lhs.y2 != rhs.y2) return lhs.y2 < rhs.y2;
        return lhs.op < rhs.op;
    });

    ll sum = 0;
    int lastX = lines[0].x;
    for(int i = 0; i < n * 2; ++i){
        const Line& line = lines[i];
        if(lastX != line.x){
            sum += (ll)(line.x - lastX) * segment1[0];
            lastX = line.x;
        }
        updateSegment(line.y1, line.y2, -line.op, 0, MAX_SIZE - 1, 0);
    }
    return sum;
}

int main(void){
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    int pos[4];
    in >> n;
    for(int i = 0; i < n; ++i){
        for(int i = 0; i < 4; ++i) in >> pos[i];
        for(int i = 0; i < 4; ++i) pos[i] = coord2Index(pos[i]);
        lines[i * 2] = { pos[0], pos[1], pos[3] - 1, Line::EOP::LEFT};
        lines[i * 2 + 1] = { pos[2], pos[1], pos[3] - 1, Line::EOP::RIGHT};
    }
    out << solution() << '\n';

#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}