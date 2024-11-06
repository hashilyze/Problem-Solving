// [Beakjoon] 2667. 단지번호붙이기
// https://www.acmicpc.net/problem/2667

#include <algorithm>
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
int N;
bool isVisited[25][25];
std::vector<int> areas;


int floodFill(int sx, int sy){
   int area = 1;
   std::queue<pii> q; q.push({sx, sy});
   isVisited[sy][sx] = true;
   
   while (!q.empty()) {
      pii pos = q.front(); q.pop();
      for(int i = 0; i < 4; ++i){
         int nx = pos.first + dx[i], ny = pos.second + dy[i];
         if(nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
         if(isVisited[ny][nx]) continue;

         ++area;
         q.push({nx, ny});
         isVisited[ny][nx] = true;
      }
   }
   return area;
}

void solution(){
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < N; ++x){
         if(isVisited[y][x]) continue;
         areas.push_back(floodFill(x, y));
      }
   }
   std::sort(areas.begin(), areas.end());
}

int main(void){
   FASTIO

   std::cin >> N;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < N; ++x){
         char b;
         std::cin >> b;
         isVisited[y][x] = b == '0';
      }
   }
   solution();
   std::cout << areas.size() << '\n';
   for(int i = 0; i < areas.size(); ++i) std::cout << areas[i] << '\n';

   return 0;
}   