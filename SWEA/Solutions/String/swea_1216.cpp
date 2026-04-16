// [SWEA] 1216. [S/W 문제해결 기본] 3일차 - 회문2

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 100;
// variables
char mat[SIZE][SIZE];


int solution(){
   for(int N = SIZE; N > 0; --N){
      // 행 단위: (y, x) ~ (y , x + N)
      for(int y = 0; y < SIZE; ++y){
         for(int x = 0; x < SIZE - N + 1; ++x){
            bool isPalindrome = true;
            int left = x, right = x + N - 1;
            while(left < right){
               if(mat[y][left] != mat[y][right]){
                  isPalindrome = false;
                  break;
               }
               ++left; --right;
            }
            if(isPalindrome) return N;
         }
      }
      // 열 단위: (y, x) ~ (y + N, x)
      for(int x = 0; x < SIZE; ++x){
         for(int y = 0; y < SIZE - N + 1; ++y){
            bool isPalindrome = true;
            int bot = y, top = y + N - 1;
            while(bot < top){
               if(mat[bot][x] != mat[top][x]){
                  isPalindrome = false;
                  break;
               }
               ++bot; --top;
            }
            if(isPalindrome) return N;
         }
      }
   }
   return 0;
}

int main(int argc, char **argv) {
   FASTIO
   
   int T = 10;
   //std::cin >> T;
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