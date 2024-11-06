// [Beakjoon] 1926. 그림
// https://www.acmicpc.net/problem/1926

#include <iostream>
#include <queue>
#include <utility>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
// variables
int N, M;
bool isVisited[500][500];


int floodFill(int sx, int sy){
   int area = 1;
   std::queue<pii> q; q.push({sx, sy});
   isVisited[sy][sx] = true;
   
   while (!q.empty()) {
      pii pos = q.front(); q.pop();
      for(int i = 0; i < 4; ++i){
         int nx = pos.first + dx[i], ny = pos.second + dy[i];
         if(nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
         if(isVisited[ny][nx]) continue;

         ++area;
         q.push({nx, ny});
         isVisited[ny][nx] = true;
      }
   }
   return area;
}

pii solution(){
   int cnt = 0, max = 0;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         if(isVisited[y][x]) continue;
         ++cnt;
         max = std::max(max, floodFill(x, y));
      }
   }
   return {cnt, max};
}

int main(void){
   FASTIO

   std::cin >> N >> M;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         std::cin >> isVisited[y][x];
         isVisited[y][x] = !isVisited[y][x];
      }
   }
   pii ret = solution();
   std::cout << ret.first << '\n' << ret.second;

   return 0;
}   