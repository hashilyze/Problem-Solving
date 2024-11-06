// [Beakjoon] 11403. 경로 찾기
// https://www.acmicpc.net/problem/11403

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX = 100'000;
// variables
int N;
int d[100][100];

void solution(){
   for(int m = 0; m < N; ++m){
      for(int s = 0; s < N; ++s){
         for(int e = 0; e < N; ++e){
            if(d[s][e] > d[s][m] + d[m][e]){
               d[s][e] = d[s][m] + d[m][e];
            }
         }
      }
   }
}

int main(void){
   FASTIO
   
   std::cin >> N;
   for(int u = 0; u < N; ++u){
      for(int v = 0; v < N; ++v){
         std::cin >> d[u][v];
         if(d[u][v] == 0) d[u][v] = MAX;
      }
   }
   solution();
   for(int u = 0; u < N; ++u){
      for(int v = 0; v < N; ++v){
         d[u][v] = d[u][v] == MAX ? 0 : 1;
         std::cout << d[u][v] << ' ';
      }
      std::cout << '\n';
   }
   

   return 0;
}   