// [Beakjoon] 5014. 스타트링크
// https://www.acmicpc.net/problem/5014

#include <cstring>
#include <iostream>
#include <queue>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int F, S, G, U, D;
int count[1'000'001];

int solution(){
   std::memset(count, 0xFF, sizeof(count));
   count[S] = 0;
   std::queue<int> q; 
   if(S + U <= F) { q.push(S + U); count[S + U] = 1; }
   if(1 <= S - D) { q.push(S - D); count[S - D] = 1; }

   while(!q.empty()){
      int stage = q.front(); q.pop();
      int u = stage + U, d = stage - D;
      if(u <= F && count[u] == -1) {
         q.push(u);
         count[u] = count[stage] + 1;
      }
      if(1 <= d && count[d] == -1) {
         q.push(d);
         count[d] = count[stage] + 1;
      }
   }
   return count[G];
}

int main(void){
   FASTIO

   std::cin >> F >> S >> G >> U >> D;
   int ans = solution();
   if(ans == -1) std::cout << "use the stairs";
   else std::cout << ans;

   return 0;
}   