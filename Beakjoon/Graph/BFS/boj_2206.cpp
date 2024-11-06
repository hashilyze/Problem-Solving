// Beakjoon 2206 - 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
struct Pos {
    Pos() = default;
    Pos(int x, int y, int b) : x(x), y(y), b(b) { }

    int x, y, b;
};

// constants
constexpr int MAX_N = 1'000;
// variables
int n, m;
int rank[2][MAX_N][MAX_N];


int bfs(Pos s, Pos t){
    std::queue<Pos> q;
    q.push(s);
    rank[s.b][s.y][s.x] = 1;
    
    while(!q.empty()){
        Pos u = q.front(); q.pop();
        if(u.x == t.x && u.y == t.y) return rank[u.b][u.y][u.x];
        
        static const Pos offsets[] = { 
            {1, 0, 0}, {-1, 0, 0},
            {0, 1, 0}, {0, -1, 0}
        };
        int nextRank = rank[u.b][u.y][u.x] + 1;
        for(Pos off : offsets){
            Pos v = {u.x + off.x, u.y + off.y, u.b};
            if(v.x < 0 || m <= v.x || v.y < 0 || n <= v.y) continue;

            int& vRank = rank[v.b][v.y][v.x];
            if(vRank == -1){
                vRank = nextRank;
                q.push({v.x, v.y, u.b});
            } else if(vRank == -2 && !u.b){
                rank[1][v.y][v.x] = nextRank;
                q.push({v.x, v.y, 1});
            }
        }
    } 
    return -1;
}

int main(void){
    FASTIO
    
    std::cin >> n >> m;
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < m; ++x){
            char ch;
            std::cin >> ch;
            rank[0][y][x] = rank[1][y][x] = (ch == '0' ? -1 : -2);
        }
    }
    
    int r = bfs({0, 0, 0}, {m - 1, n - 1, 1});
    std::cout << r << '\n';

    return 0;
}