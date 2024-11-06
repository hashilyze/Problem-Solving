// [Beakjoon] 2178. 미로 탐색
// https://www.acmicpc.net/problem/2178

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
int isVisited[100][100];


void solution(){
   std::queue<pii> q; q.push({0, 0});
   isVisited[0][0] = 1;
   
   while (!q.empty()) {
      pii pos = q.front(); q.pop();
      if(pos.first == M - 1 && pos.second == N - 1) return;

      for(int i = 0; i < 4; ++i){
         int nx = pos.first + dx[i], ny = pos.second + dy[i];
         if(nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
         if(isVisited[ny][nx]) continue;

         q.push({nx, ny});
         isVisited[ny][nx] = isVisited[pos.second][pos.first] + 1;
      }
   }
}

int main(void){
   FASTIO

   std::cin >> N >> M;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         char b; std::cin >> b;
         isVisited[y][x] = b == '0';
      }
   }
   solution();
   std::cout << isVisited[N - 1][M - 1];

   return 0;
}   