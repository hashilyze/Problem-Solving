// [Beakjoon] 12851. 숨바꼭질 2
// https://www.acmicpc.net/problem/12851

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 100'001;
// variables
int N, K;
int isVisited[SIZE];


std::pair<int, int> solution(){
   std::memset(isVisited, 0xFF, sizeof(isVisited));
   std::queue<int> q, nq; q.push(N);
   isVisited[N] = 0;

   while(!q.empty() || !nq.empty()){
      if(q.empty()) std::swap(q, nq);

      int x = q.front(); q.pop();
      if(x == K) {
         int cnt = 1;
         while(!q.empty()){
            if(q.front() == x) ++cnt;
            q.pop();
         }
         return {isVisited[K], cnt};
      }

      for(int nx : {x - 1, x + 1, x * 2}){
         if(nx < 0 || SIZE <= nx) continue;
         if(isVisited[nx] != -1 && isVisited[nx] < isVisited[x] + 1) continue;

         nq.push(nx);
         isVisited[nx] = isVisited[x] + 1;
      }
   }
   return {0, 0};
}

int main(void){
   FASTIO

   std::cin >> N >> K;
   auto ans =  solution();
   std::cout << ans.first << '\n' << ans.second;
   

   return 0;
}   