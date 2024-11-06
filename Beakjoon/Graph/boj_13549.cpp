// [Beakjoon] 13549. 숨바꼭질 3
// https://www.acmicpc.net/problem/13549

#include <cstring>
#include <iostream>
#include <deque>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 200'100;
// variables
int N, K;
int isVisited[SIZE];


void solution(){
   std::memset(isVisited, 0xFF, sizeof(isVisited));
   std::deque<int> q; q.push_front(N);
   isVisited[N] = 0;

   while(!q.empty()){
      int x = q.front(); q.pop_front();
      if(x == K) return;

      for(int nx : {x - 1, x + 1, x * 2}){
         if(nx < 0 || SIZE < nx) continue;
         if(isVisited[nx] != -1) continue;

         if(nx == x * 2) {
            q.push_front(nx);
            isVisited[nx] = isVisited[x];
         } else{
            q.push_back(nx);
            isVisited[nx] = isVisited[x] + 1;
         }
      }
   }
}

int main(void){
   FASTIO

   std::cin >> N >> K;
   solution();
   std::cout << isVisited[K] << '\n';

   return 0;
}   