// Beakjoon 1933 - 스카이라인
// https://www.acmicpc.net/problem/1933

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
using ll = long long;
struct rect {
    rect() = default;
    rect(int left, int right, int height) 
        : left(left), right(right), height(height) { };

    int left, right, height;
};

// constants
constexpr int MAX_N = 100'000;
// variables
int n, k = 0;
rect buildings[MAX_N];
pii skyline[MAX_N * 2];

void solution(){
    std::vector<pii> walls;
    walls.reserve(n * 2);
    for(int i = 0; i < n; ++i){
        const rect & building = buildings[i];
        walls.push_back({building.left, -building.height});
        walls.push_back({building.right, building.height});
    }
    std::sort(walls.begin(), walls.end());

    std::multiset<int> heights = { 0 };
    int max = 0;

    for(auto beg = walls.cbegin(), end = walls.cend(); beg != end; ++beg){
        if(beg->second < 0){ // left wall
            heights.insert(-beg->second);
        } else{ // right wall
            heights.erase(heights.find(beg->second));
        }

        int newMax = *heights.rbegin();
        if(newMax != max){
            max = newMax;
            skyline[k++] = { beg->first, newMax };
        }
    }
}

int main(void){
    FASTIO

    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> buildings[i].left >> buildings[i].height >> buildings[i].right;
    }

    solution();

    for(int i = 0; i < k; ++i){
        std::cout << skyline[i].first << " " << skyline[i].second << " ";
    }

    return 0;
}