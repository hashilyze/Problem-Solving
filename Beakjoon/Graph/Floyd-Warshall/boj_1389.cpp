// [Beakjoon] 1389. 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int MAX = 100'000;
// variables
int N, M;
int d[100][100];


void init(){
   for(int u = 0; u < N; ++u){
      for(int v = 0; v < N; ++v){
         d[u][v] = MAX;
      }
      d[u][u] = 0;
   }
}

void floyd(){
   for(int m = 0; m < N; ++m){
      for(int s = 0; s < N; ++s){
         for(int e = 0; e < N; ++e){
            d[s][e] = std::min(d[s][e], d[s][m] + d[m][e]);
         }
      }
   }
}

int solution(){
   floyd();
   
   int minIdx = 0, minVal = 2147483647;
   for(int u = 0; u < N; ++u){
      int sum = 0;
      for(int v = 0; v < N; ++v){
         sum += d[u][v];
      }
      if(minVal > sum){
         minVal = sum;
         minIdx = u;
      }
   }
   return minIdx;
}

int main(void){
   FASTIO

   std::cin >> N >> M;
   init();
   for(int i = 0; i < M; ++i){
      int u, v;
      std::cin >> u >> v;
      d[u - 1][v - 1] = d[v - 1][u - 1] = 1;
   }
   std::cout << solution() + 1;

   return 0;
}   