// [Beakjoon] 1707. 이분 그래프
// https://www.acmicpc.net/problem/1707

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int V, E;
std::vector<int> adj[20'001];
int isVisited[20'001];


void init(){
   std::memset(isVisited, 0xFF, sizeof(isVisited));
   for(int u = 1; u <= V; ++u) adj[u].clear();
}

bool solution(){
   std::queue<int> q;
   for(int i = 1; i <= V; ++i){
      if(isVisited[i] != -1) continue;
      q.push(i);
      isVisited[i] = 0;

      while (!q.empty()) {
         int u = q.front(); q.pop();
         for(int v : adj[u]){
            if(isVisited[v] == isVisited[u]) return false;
            if(isVisited[v] != -1) continue;
            q.push(v);
            isVisited[v] = (isVisited[u] + 1) & 1;
         }
      }
   }
   return true;
}


int main(void){
   FASTIO

   int T;
   std::cin >> T;
   while(T--){
      std::cin >> V >> E;
      init();
      for(int i = 0; i < E; ++i){
         int u, v;
         std::cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      std::cout << (solution() ? "YES" : "NO") << '\n';
   }

   return 0;
}   