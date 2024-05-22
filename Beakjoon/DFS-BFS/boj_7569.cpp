// Beakjoon 7579 - 토마토
// https://www.acmicpc.net/problem/7579

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
struct Vec { 
    Vec() = default;
    Vec(int x, int y, int z) : x(x), y(y), z(z) { }
    int x, y, z; 
};
// constants
constexpr int MAX_N = 100;
// variables
int n, m, k;
int rank[MAX_N][MAX_N][MAX_N];
std::vector<Vec> starts;


int floodFill(){
    std::queue<Vec> q;
    for(Vec s : starts) q.push(s);

    while(!q.empty()){
        Vec u = q.front(); q.pop();
        
        static const Vec offsets[] = {
            {1, 0, 0}, {-1, 0, 0},
            {0, 1, 0}, {0, -1, 0},
            {0, 0, 1}, {0, 0, -1}
        };
        
        for(Vec off : offsets){
            Vec v = { u.x + off.x, u.y + off.y, u.z + off.z };
            if(v.x < 0 || n <= v.x
            || v.y < 0 || m <= v.y
            || v.z < 0 || k <= v.z){ // out-of-range
                continue;
            }
            if(rank[v.z][v.y][v.x] != -1) continue;
            
            rank[v.z][v.y][v.x] = rank[u.z][u.y][u.x] + 1;
            q.push(v);
        }
    }
    
    int r = 0;
    for(int z = 0; z < k; ++z){
        for(int y = 0; y < m; ++y){
            for(int x = 0; x < n; ++x){
                if(rank[z][y][x] == -2) continue;
                if(rank[z][y][x] == -1) return -1;

                r = std::max(r , rank[z][y][x]);
            }
        }
    }
    return r;
}


int main(void){
    FASTIO
    
    std::cin >> n >> m >> k;
    for(int z = 0; z < k; ++z){
        for(int y = 0; y < m; ++y){
            for(int x = 0; x < n; ++x){
                int i;
                std::cin >> i;
                switch(i){
                case -1:{ // None
                    rank[z][y][x] = -2;
                } break;
                case 0:{ // Unvisited
                    rank[z][y][x] = -1;
                } break;
                case 1:{ // Visited (Start)
                    rank[z][y][x] = 0;
                    starts.push_back({x, y, z});
                }
                }
            }
        }
    }
    std::cout << floodFill() << '\n';

    return 0;
}