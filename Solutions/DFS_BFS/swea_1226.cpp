// [SWEA] 1226. [S/W 문제해결 기본] 7일차 - 미로1

#include <iostream>
#include <queue>
#include <utility>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
constexpr int SIZE = 16;
constexpr int EMPTY = 0, WALL = 1, START = 2, DEST = 3, UNVISTED = 0, VISITED = 4;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
// variables
int mat[SIZE][SIZE];


bool bfs(pii S, pii T){
   std::queue<pii> q;
   q.push(S);
   mat[S.second][S.first] = VISITED;

   while(!q.empty()){
      pii u = q.front(); q.pop();
      for(int i = 0; i < 4; ++i){
         pii v = {u.first + dx[i], u.second + dy[i]};
         if(v.first < 0 || SIZE <= v.first || v.second < 0 || SIZE <= v.second) continue;
         if(mat[v.second][v.first] == VISITED || mat[v.second][v.first] == WALL) continue;

         mat[v.second][v.first] = VISITED;
         q.push(v);
         if(v == T) return true;
         
      }
   }
   return false;
}


int main(int argc, char **argv) {
   FASTIO
   
   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::cin >> t;
      pii S, T;
      
      char digit;
      for(int y = 0; y < SIZE; ++y){
         for(int x = 0; x < SIZE; ++x){
            std::cin >> digit;
            mat[y][x] = digit - '0';
            if(mat[y][x] == 2) S = {x, y};
            else if(mat[y][x] == 3) T = {x, y};
         }
      }

      std::cout << '#' << t << ' ' << (bfs(S, T) ? 1 : 0) << '\n';
   }

   return 0;
}