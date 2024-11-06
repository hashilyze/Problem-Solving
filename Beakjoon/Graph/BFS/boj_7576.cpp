// [Beakjoon] 7576. 토마토
// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
// variables
int N, M;
int isVisited[1000][1000];
std::vector<pii> start;


int solution(){
   std::queue<pii> q; 
   for(const pii& p : start) q.push(p);
   
   while (!q.empty()) {
      pii pos = q.front(); q.pop();
      for(int i = 0; i < 4; ++i){
         int nx = pos.first + dx[i], ny = pos.second + dy[i];
         if(nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
         if(isVisited[ny][nx]) continue;

         q.push({nx, ny});
         isVisited[ny][nx] = isVisited[pos.second][pos.first] + 1;
      }
   }

   int max = 1;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         if(isVisited[y][x] == 0) return -1;
         max = std::max(max, isVisited[y][x]);
      }
   }
   return max - 1;
}

int main(void){
   FASTIO

   std::cin >> M >> N;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         std::cin >> isVisited[y][x];
         if(isVisited[y][x] == 1) start.push_back({x, y});
      }
   }
   std::cout << solution();
   return 0;
}   