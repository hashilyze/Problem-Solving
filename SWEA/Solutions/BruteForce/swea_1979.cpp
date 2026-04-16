// [SWEA] 1979. 어디에 단어가 들어갈 수 있을까

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int MAX_N = 15;
// variables
int mat[MAX_N][MAX_N];


int solution(int N, int K){
   int cnt = 0;
   
   for(int y = 0; y < N; ++y){ // 행 검사
      int len = 0;
      for(int x = 0; x < N; ++x){
         if(mat[y][x] == 0) {
            if(len == K) ++cnt;
            len = 0;
         } else{
            ++len;
         }
      }
      if(len == K) ++cnt;
   }

   for(int x = 0; x < N; ++x){ // 열 검사
      int len = 0;
      for(int y = 0; y < N; ++y){
         if(mat[y][x] == 0) {
            if(len == K) ++cnt;
            len = 0;
         } else{
            ++len;
         }
      }
      if(len == K) ++cnt;
   }
   return cnt;
}

int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int N, K;
      std::cin >> N >> K;
      for(int y = 0; y < N; ++y){
         for(int x = 0; x < N; ++x){
            std::cin >> mat[y][x];
         }
      }
      std::cout << '#' << t << ' ' << solution(N, K) << '\n';
   }

   return 0;
}