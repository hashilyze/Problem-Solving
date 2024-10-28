// [SWEA] 1219. [S/W 문제해결 기본] 4일차 - 길찾기

#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 100;
constexpr int SRC = 0, DEST = 99;
// variables
std::vector<int> E[SIZE];
bool isVisited[SIZE];


bool dfs(int u, int v){
   if(u == v) 
      return true;
   if(isVisited[u]) return false;
   isVisited[u] = true;
   
   for(auto w : E[u]){
      if(dfs(w, v)) {
         return true;
      }
   }
   
   isVisited[u] = false;
   return false;
}

void init(){
   for(auto &e : E) e.clear();
   std::memset(isVisited, 0x00, sizeof(isVisited));
}

int main(int argc, char **argv) {
   FASTIO
   
   int T = 10;
   //std::cin >> T;
   for(int t = 1; t <= T; ++t){
      init();

      int n;
      std::cin >> t >> n;
      for(int i = 0; i < n; ++i){
         int u, v;
         std::cin >> u >> v;
         E[u].push_back(v);
      }

      std::cout << '#' << t << ' ' << (dfs(SRC, DEST) ? 1 : 0) << '\n';
   }

   return 0;
}