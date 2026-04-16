// [SWEA] 1974. 스도쿠 검증

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int SIZE_L = 9;
const int SIZE_S = 3;
const unsigned int MASK = 0b111111111;
// variables
int mat[SIZE_L][SIZE_L];


bool solution(){
   // 행 검사
   for(int y = 0; y < SIZE_L; ++y){
      int flag = 0x00;
      for(int x = 0; x < SIZE_L; ++x){
         flag |= 0x01 << (mat[y][x] - 1);
      }
      if((flag & MASK) != MASK) return false;
   }
   // 열 검사
   for(int x = 0; x < SIZE_L; ++x){
      int flag = 0x00;
      for(int y = 0; y < SIZE_L; ++y){
         flag |= 0x01 << (mat[y][x] - 1);
      }
      if((flag & MASK) != MASK) return false;
   }
   // 격자 검사
   for(int y = 0; y < SIZE_L; y += 3){
      for(int x = 0; x < SIZE_L; x += 3){
         int flag = 0x00;
         for(int dy = 0; dy < SIZE_S; ++dy){
            for(int dx = 0; dx < SIZE_S; ++dx){
               flag |= 0x01 << (mat[y + dy][x + dx] - 1);
            }
         }   
         if((flag & MASK) != MASK) return false;  
      }
   }

   return true;   
}


int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      for(int y = 0; y < SIZE_L; ++y){
         for(int x = 0; x < SIZE_L; ++x){
            std::cin >> mat[y][x];
         }
      }
      std::cout << '#' << t << ' ' << (solution() ? 1 : 0) << '\n';
   }

   return 0;
}