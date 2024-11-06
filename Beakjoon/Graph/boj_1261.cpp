// [Beakjoon] 1261. 알고스팟
// https://www.acmicpc.net/problem/1261

#include <cstring>
#include <iostream>
#include <deque>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
// variables
int N, M;
char mat[100][100];
int isVisited[100][100];


int solution(){
   std::memset(isVisited, 0xFF, sizeof(isVisited));
   const int sx = 0, sy = 0, tx = M - 1, ty = N - 1;
   std::deque<pii> deq; deq.push_back({sx, sy});
   isVisited[sy][sx] = 0;

   while(!deq.empty()){
      pii pos = deq.front(); deq.pop_front();
      const int x = pos.first, y = pos.second;
      if(tx == x && ty == y) return isVisited[ty][tx];

      for(int i = 0; i < 4; ++i){
         const int nx = x + dx[i], ny = y + dy[i];
         if(nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
         if(isVisited[ny][nx] != -1) continue;
         
         if(mat[ny][nx] == '1'){
            isVisited[ny][nx] = isVisited[y][x] + 1;
            deq.push_back({nx, ny});
         } else if(mat[ny][nx] == '0'){
            isVisited[ny][nx] = isVisited[y][x];
            deq.push_front({nx, ny});
         }
      }
   }
   return isVisited[ty][tx];
}

int main(void){
   FASTIO

   std::cin >> M >> N;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         std::cin >> mat[y][x];
      }
   }
   std::cout << solution();

   return 0;
}   