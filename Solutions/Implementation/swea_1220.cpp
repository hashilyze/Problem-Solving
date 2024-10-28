// [SWEA] 1220. [S/W 문제해결 기본] 5일차 - Magnetic

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 100;
// variables
int mat[SIZE][SIZE];


int solution(){
   int cnt = 0;
   for(int x = 0; x < SIZE; ++x){
      for(int y = 0; y < SIZE; ++y){ // "[1]+[2]+"가 하나의 교착상태
         if(mat[y][x] == 0) continue;
         
         bool red = false, blue = false;
         while(y < SIZE && (mat[y][x] == 1 || mat[y][x] == 0)) { red = true;  ++y; } // "[1]+"
         while(y < SIZE && (mat[y][x] == 2 || mat[y][x] == 0)) { blue = true; ++y; } // "[2]+"
         
         if(red && blue) ++cnt;
         if(red || blue) --y;
      }
   }

   return cnt;
}


int main(int argc, char **argv) {
   FASTIO
   
   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      int n;
      std::cin >> n;

      for(int y = 0; y < SIZE; ++y){
         for(int x = 0; x < SIZE; ++x){
            std::cin >> mat[y][x];
         }
      }

      std::cout << '#' << t << ' ' << solution() << '\n';
   }

   return 0;
}