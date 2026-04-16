// [SWEA] 1209. [S/W 문제해결 기본] 2일차 - Sum

#include <iostream>
// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int T = 10;
const int SIZE = 100;
// variables
int mat[SIZE][SIZE];

int solution(){
   int max = 0;
   // 각 행에 대해
   for(int y = 0; y < SIZE; ++y){
      int sum = 0;
      for(int x = 0; x < SIZE; ++x){
         sum += mat[y][x];
      }
      max = std::max(max, sum);
   }
   // 각 열에 대해
   for(int x = 0; x < SIZE; ++x){
      int sum = 0;
      for(int y = 0; y < SIZE; ++y){
         sum += mat[y][x];
      }
      max = std::max(max, sum);
   }
   // 대각선
   {
      int sum = 0;
      for(int x = 0; x < SIZE; ++x){
         sum += mat[x][x];
      }
      max = std::max(max, sum);
   }
   {
      int sum = 0;
      for(int x = 0; x < SIZE; ++x){
         sum += mat[x][SIZE - 1 - x];
      }
      max = std::max(max, sum);
   }

   return max;
}

int main(int argc, char **argv) {
   FASTIO

   for(int t = 1; t <= T; ++t){
      std::cin >> t;
      for(int y = 0; y < SIZE; ++y){
         for(int x = 0; x < SIZE; ++x){
            std::cin >> mat[y][x];
         }
      }
      std::cout << '#' << t << ' ' << solution() << '\n';
   }

   return 0;
}