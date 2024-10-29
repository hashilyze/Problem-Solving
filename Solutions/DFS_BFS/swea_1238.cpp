// [SWEA] 1238. [S/W 문제해결 기본] 10일차 - Contact

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 100;
// variables
int N, S;
std::vector<int> edges[SIZE + 1];
int isVisited[SIZE + 1];

int bfs(int start){
   std::queue<int> Q;
   Q.push(start);
   isVisited[start] = 1;

   while(!Q.empty()){
      int u = Q.front(); Q.pop();
      bool propagate = false;
      for(int v : edges[u]){
         if(isVisited[v]) continue;

         Q.push(v);
         isVisited[v] = isVisited[u] + 1;
         propagate = true;
      }
   }
   
   int last = SIZE - 1;
   for(int i = SIZE - 2; i > 0; --i){
      if(isVisited[last] < isVisited[i]) last = i;
   }
   return last;
}

void init(){
   for(int i = 0; i <= SIZE; ++i) edges[i].clear();
   std::memset(isVisited, 0x00, sizeof(isVisited));
}

int main(int argc, char **argv) {
   FASTIO

   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      init();
      
      std::cin >> N >> S;
      for(int i = 0; i < (N >> 1); ++i){
         int from, to;
         std::cin >> from >> to;
         edges[from].push_back(to);
      }
      std::cout << '#' << t << ' ' << bfs(S) << '\n';
   }
   

   return 0;
}