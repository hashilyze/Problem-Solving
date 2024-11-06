// [Beakjoon] 7562. 나이트의 이동
// https://www.acmicpc.net/problem/7562

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
// variables
int T;
int isVisited[300][300];

int solution(int I, int sx, int sy, int tx, int ty){
   std::memset(isVisited, 0xFF, sizeof(isVisited));
   std::queue<pii> q; q.push({sx, sy});
   isVisited[sy][sx] = 0;

   while(!q.empty()){
      pii pos = q.front(); q.pop();
      if(pos.first == tx && pos.second == ty) return isVisited[ty][tx];
      for(int i = 0; i < 8; ++i){
         int nx = pos.first + dx[i], ny = pos.second + dy[i];
         if(nx < 0 || I <= nx || ny < 0 || I <= ny) continue;
         if(isVisited[ny][nx] != -1) continue;

         q.push({nx, ny});
         isVisited[ny][nx] = isVisited[pos.second][pos.first] + 1;
      }
   }
   return -1;
}

int main(void){
   FASTIO

   std::cin >> T;
   while(T--){
      int I, sx, sy, tx, ty;
      std::cin >> I >> sx >> sy >> tx >> ty;
      std::cout << solution(I, sx, sy, tx, ty) << '\n';
   }

   return 0;
}   