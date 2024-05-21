// Beakjoon 7576 - 토마토
// https://www.acmicpc.net/problem/7576

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
constexpr int MAX_N = 1'000, MAX_M = MAX_N;
// variables
int n, m;
int rank[MAX_M][MAX_N];
std::vector<pii> start;


void floodFill(){
    std::queue<pii> q;
    for(const auto & s : start) q.push(s);
    
    int last = 0;
    while(!q.empty()){
        pii u = q.front(); q.pop();
        
        pii offsets[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        for(const pii &off : offsets){
            pii v = { u.first + off.first, u.second + off.second };
            if(v.first < 0 || m <= v.first || v.second < 0 || n <= v.second) continue;
            if(rank[v.second][v.first] != -1) continue;

            rank[v.second][v.first] = rank[u.second][u.first] + 1;
            q.push(v);
        }
    }
}

int main(void){
    FASTIO

    std::cin >> m >> n;
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < m; ++x){
            int r;
            std::cin >> r;
            switch (r) {
            case 0: {
                rank[y][x] = -1;
            } break;
            case 1: {
                rank[y][x] = 0;
                start.push_back({x, y});
            } break;
            case -1: {
                rank[y][x] = -2;
            } break;
            }
        }
    }

    floodFill();

    int max = 0;
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < m; ++x){
            if(rank[y][x] == -2) continue;

            if(rank[y][x] == -1) {
                std::cout << "-1\n";
                exit(0);
            }
            
            max = std::max(max, rank[y][x]);
        }
    }
    std::cout << max << '\n';

    return 0;
}