// Beakjoon 2170 - 선 긋기
// https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>
#include <algorithm>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int ,int>;
// variables
int n;
std::vector<pii> lines;

int soultion(){
    std::sort(lines.begin(), lines.end());
    
    std::vector<pii> blocks;
    blocks.reserve(n);
    blocks.push_back(lines.front());
    for(auto beg = lines.cbegin() + 1, end = lines.cend(); beg != end; ++beg){
        const pii& line = *beg;
        pii& block = blocks.back();
        
        if(line.first <= block.second) {
            block.second = std::max(block.second, line.second);
        } else{
            blocks.push_back(line);
        }
    }
    
    int length = 0;
    for(auto beg = blocks.cbegin(), end = blocks.cend(); beg != end; ++beg){
        length += beg->second - beg->first;
    }
    return length;
}

int main(void){
    FASTIO

    std::cin >> n;
    lines.reserve(n);

    for(int i = 0; i < n; ++i){
        int x, y;
        std::cin >> x >> y;
        lines.push_back({x, y});
    }

    std::cout << soultion() << '\n';

    return 0;
}