// [Beakjoon] 1697. 숨바꼭질
// https://www.acmicpc.net/problem/1697

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 200'100;
// variables
int N, K;
int isVisited[SIZE];


int solution(){
   std::memset(isVisited, 0xFF, sizeof(isVisited));
   std::queue<int> q; q.push(N);
   isVisited[N] = 0;

   while(!q.empty()){
      int x = q.front(); q.pop();
      if(x == K) return isVisited[K];

      for(int nx : {x - 1, x + 1, x * 2}){
         if(nx < 0 || SIZE < nx) continue;
         if(isVisited[nx] != -1) continue;

         q.push(nx);
         isVisited[nx] = isVisited[x] + 1;
      }
   }
   return isVisited[K];
}

int main(void){
   FASTIO

   std::cin >> N >> K;
   std::cout << solution();

   return 0;
}   