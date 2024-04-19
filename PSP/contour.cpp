// 문제해결 기법 과제-15

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

//#define ONLINE_JUDGE

// === File Control ====
const std::string FILE_NAME = "contour";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

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
constexpr int MAX_N = 200000;
// variables
int n, k = 0;
rect buildings[MAX_N];
pii skyline[MAX_N * 2];

void makeSkyline(){
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
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    int l, h, r;
    int i = 0, t = 1;
    while(in >> l >> h >> r){
        if(l != 0 || h != 0 || r != 0){
            buildings[i].left = l;
            buildings[i].height = h;
            buildings[i].right = r;
            ++i;
            continue;
        }
        n = i;
        makeSkyline();

        out << "Test Case #" << t << " : ";
        ll area = 0LL;
        for(int i = 1; i < k; ++i){
            ll width = skyline[i].first - skyline[i - 1].first;
            ll height = skyline[i - 1].second;
            area += width * height;

            if(skyline[i].second == 0) {
                out << area << " ";
                area = 0LL;
            }
        }
        out << '\n';
        ++t;
        i = 0; n = 0; k = 0;
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}