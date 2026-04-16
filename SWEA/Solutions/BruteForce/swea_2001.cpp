// [SWEA] 2001. 파리 퇴치

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int MAX_N = 15;
// variables
int N, M;
int mat[MAX_N][MAX_N];


int solution(){
   int max = 0;

   int sum = 0;
   for(int y = 0; y < M; ++y){      // init: (0, 0)
      for(int x = 0; x < M; ++x){
         sum += mat[y][x];
      }
   }
   max = sum;

   for(int y = 0; y <= N - M; ++y){
      if(y != 0){ // += (0, 1)
         int x = y % 2 ? N - M : 0;
         for(int i = 0; i < M; ++i) sum -= mat[y - 1][x + i];
         for(int i = 0; i < M; ++i) sum += mat[y + M - 1][x + i];
         max = std::max(max, sum);
      }

      if(y % 2){  // -= (1, 0)
         for(int x = N - M - 1; x >= 0; --x){ 
            for(int i = 0; i < M; ++i) sum -= mat[y + i][x + M];
            for(int i = 0; i < M; ++i) sum += mat[y + i][x];
            max = std::max(max, sum);
         }
      } else{     // += (1, 0)
         for(int x = 1; x <= N - M; ++x){ 
            for(int i = 0; i < M; ++i) sum -= mat[y + i][x - 1];
            for(int i = 0; i < M; ++i) sum += mat[y + i][x + M - 1];
            max = std::max(max, sum);
         }
      }
   }

   return max;
}


int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N >> M;
      for(int y = 0; y < N; ++y){
         for(int x = 0; x < N; ++x){
            std::cin >> mat[y][x];
         }
      }

      std::cout << '#' << t << ' ' << solution() << '\n';
   }

   return 0;
}