// [SWEA] 1961. 숫자 배열 회전

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 7;
// variables
int N;
int mat[4][MAX_N][MAX_N];


void solution(){
   // 90도 회전
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < N; ++x){
         mat[1][x][N - 1 - y] = mat[0][y][x];
      }
   }
   // 180도 회전
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < N; ++x){
         mat[2][N - 1 - y][N - 1 - x] = mat[0][y][x];
      }
   }
   // 270도 회전
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < N; ++x){
         mat[3][N - 1 - x][y] = mat[0][y][x];
      }
   }
}

int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;
      for(int y = 0; y < N; ++y){
         for(int x = 0; x < N; ++x){
            std::cin >> mat[0][y][x];
         }
      }

      solution();

      std::cout << '#' << t << '\n';
      for(int y = 0; y < N; ++y){
         for(int z = 1; z < 4; ++z){
            for(int x = 0; x < N; ++x){
               std::cout << mat[z][y][x];
            }
            std::cout << ' ';
         }
         std::cout << '\n';
      }
   }

   return 0;
}