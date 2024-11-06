// [Beakjoon] 13913. 숨바꼭질 4
// https://www.acmicpc.net/problem/13913

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 200'100;
// variables
int N, K;
int isVisited[SIZE];
int parents[SIZE];


void solution(){
   std::memset(isVisited, 0xFF, sizeof(isVisited));
   std::memset(parents, 0xFF, sizeof(parents));
   std::queue<int> q; q.push(N);
   isVisited[N] = 0;

   while(!q.empty()){
      int x = q.front(); q.pop();
      if(x == K) return;


      for(int nx : {x - 1, x + 1, x * 2}){
         if(nx < 0 || SIZE < nx) continue;
         if(isVisited[nx] != -1) continue;

         q.push(nx);
         isVisited[nx] = isVisited[x] + 1;
         parents[nx] = x;
      }
   }
}

int main(void){
   FASTIO

   std::cin >> N >> K;
   solution();
   std::cout << isVisited[K] << '\n';

   std::vector<int> path;
   int p = K;
   while(parents[p] != -1){
      path.push_back(p);
      p = parents[p];
   }
   path.push_back(p);

   for(auto rbeg = path.rbegin(), rend = path.rend(); rbeg != rend; ++rbeg){
      std::cout << *rbeg << ' ';
   }


   return 0;
}   