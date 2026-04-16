// [SWEA] 1210. [S/W 문제해결 기본] 2일차 - Ladder1

#include <algorithm>
#include <iostream>
// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int T = 10;
constexpr int SIZE = 100;
constexpr int EMPTY = 0, LADDER = 1, DEST = 2;
// variables
int mat[SIZE][SIZE];

int solution(){
   int y = SIZE - 1;
   int x = std::find(mat[SIZE - 1], mat[SIZE - 1] + SIZE, DEST) - mat[SIZE - 1];

   while(y != 0){
      --y;
      if(0 <= x - 1 && mat[y][x - 1] == LADDER){ // 왼쪽 사다리 확인
         while(0 <= x - 1 && mat[y][x - 1] == LADDER) --x;
      } else if(x + 1 < SIZE && mat[y][x + 1] == LADDER){ // 오른쪽 사다리 확인
         while(x + 1 < SIZE && mat[y][x + 1] == LADDER) ++x;
      }
   }
   return x;
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