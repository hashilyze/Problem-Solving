// [SWEA] 1211. [S/W 문제해결 기본] 2일차 - Ladder2

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

int length(int start){
   if(mat[0][start] == EMPTY) return 10'001;
   
   int len = 1;
   int y = 0, x = start;
   while(y < SIZE - 1){
      ++y; ++len;
      if(0 <= x - 1 && mat[y][x - 1] == LADDER){ // 왼쪽 사다리 확인
         while(0 <= x - 1 && mat[y][x - 1] == LADDER) { --x; ++len; }
      } else if(x + 1 < SIZE && mat[y][x + 1] == LADDER){ // 오른쪽 사다리 확인
         while(x + 1 < SIZE && mat[y][x + 1] == LADDER) { ++x; ++len; }
      }
   }
   return len;
}

int solution(){
   int x = SIZE - 1, min = length(x);
   for(int nextX = x - 1; nextX >= 0; --nextX){
      int len = length(nextX);
      if(len < min){
         x = nextX;
         min = len;
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