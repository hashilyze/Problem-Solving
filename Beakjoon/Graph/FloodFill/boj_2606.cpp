// [Beakjoon] 2606. 바이러스
// https://www.acmicpc.net/problem/2606

#include <cstring>
#include <iostream>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int V, E;
std::vector<int> adj[101];
int isVisited[101];


int floodFill(int u){
   if(isVisited[u]) return 0;
   isVisited[u] = true; 
   int sum = 1;
   for(int v : adj[u]) sum += floodFill(v);
   return sum;
}

int main(void){
   FASTIO

   std::cin >> V >> E;
   for(int i = 0; i < E; ++i){
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   std::cout << floodFill(1) - 1;

   return 0;
}   