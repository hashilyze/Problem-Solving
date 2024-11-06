// [Beakjoon] 2583. 영역 구하기
// https://www.acmicpc.net/problem/2583

#include <algorithm>
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
int M, N, K;
bool isVisited[100][100];


void fillRect(int x1, int y1, int x2, int y2){
   for(int y = y1; y < y2; ++y){
      for(int x = x1; x < x2; ++x){
         isVisited[y][x] = true;
      }
   }
}

int bfs(int sx, int sy){
   int area = 1;
   std::queue<pii> q;   q.push({sx, sy});
   isVisited[sy][sx] = true;

   while(!q.empty()){
      pii pos = q.front(); q.pop();
      for(int i = 0; i < 4; ++i){
         int nx = pos.first + dx[i], ny = pos.second + dy[i];
         if(nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
         if(isVisited[ny][nx]) continue;
         isVisited[ny][nx] = true;
         q.push({nx, ny});
         ++area;
      }
   }
   return area;
}

int solution(int *out){
   int cnt = 0;
   for(int y = 0; y < M; ++y){
      for(int x = 0; x < N; ++x){
         if(isVisited[y][x]) continue;
         out[cnt++] = bfs(x, y);
      }
   }
   std::sort(out, out + cnt);
   return cnt;
}

int main(void){
   FASTIO
   
   std::cin >> M >> N >> K;
   for(int i = 0; i < K; ++i){
      int x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      fillRect(x1, y1, x2, y2);
   }
   
   int area[5000];
   int cnt = solution(area);
   std::cout << cnt << '\n';
   for(int i = 0; i < cnt; ++i) std::cout << area[i] << ' ';

   return 0;
}   