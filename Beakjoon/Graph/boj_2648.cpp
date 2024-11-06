// [Beakjoon] 2468. 안전 영역
// https://www.acmicpc.net/problem/2468

#include <cstring>
#include <iostream>
#include <queue>
#include <set>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
// variables
int N;
int heights[100][100];
bool isVisited[100][100];
std::set<int> distinctedHeights;


void floodFill(int sx, int sy){
   std::queue<pii> q; q.push({sx, sy});
   isVisited[sy][sx] = true;
   
   while(!q.empty()){
      pii pos = q.front(); q.pop();
      for(int i = 0; i < 4; ++i){
         int nx = pos.first + dx[i], ny = pos.second + dy[i];
         if(nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
         if(isVisited[ny][nx]) continue;

         q.push({nx, ny});
         isVisited[ny][nx] = true;
      }
   }
}

int countSafeZone(int h){
   for(int y = 0; y < N; ++y){ // init
      for(int x = 0; x < N; ++x){
         isVisited[y][x] = heights[y][x] <= h;
      }
   }

   int cnt = 0;
   for(int y = 0; y < N; ++y){ // solution
      for(int x = 0; x < N; ++x){
         if(isVisited[y][x]) continue;
         ++cnt;
         floodFill(x, y);
      }
   }
   return cnt;
}

int solution(){
   int max = 1;
   for(int h : distinctedHeights){
      max = std::max(max, countSafeZone(h));
   }
   return max;
}

int main(void){
   FASTIO

   std::cin >> N;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < N; ++x){
         std::cin >> heights[y][x];
         distinctedHeights.insert(heights[y][x]);
      }
   }
   std::cout << solution();

   return 0;
}   