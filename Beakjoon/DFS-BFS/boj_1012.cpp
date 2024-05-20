// Beakjoon 1012번 - 유기농 배추
// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <cstring>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
constexpr int MAX_N = 50;
constexpr int MAX_M = 50;
// variables
int n, m, k;
bool isVisited[MAX_N][MAX_M];


int dfs(int x, int y){
    if(isVisited[y][x]) return 0;
    isVisited[y][x] = true;

    int cnt = 1;
    if(0 <= x - 1) cnt += dfs(x - 1, y);
    if(x + 1 < m)  cnt += dfs(x + 1, y);
    if(0 <= y - 1) cnt += dfs(x, y - 1);
    if(y + 1 < n)  cnt += dfs(x, y + 1);

    return cnt;
}

int dfsAll(){
    int count = 0;
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < m; ++x){
            if(!isVisited[y][x]){
                ++count;
                dfs(x, y);
            }
        }
    }
    return count;
}

int main(void){
    FASTIO

    int t;
    std::cin >> t;
    while(t--){
        std::cin >> m >> n >> k;
        std::memset(isVisited, 0x01, sizeof(isVisited));
        while(k--){
            int x, y;
            std::cin >> x >> y;
            isVisited[y][x] = false;
        }

        std::cout << dfsAll() << '\n';
    }

    return 0;
}