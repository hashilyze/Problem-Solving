// [SWEA] 1954. 달팽이 숫자

#include <cstring>
#include <iostream>
#include <utility>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using pii = std::pair<int, int>;
// constants
const int MAX_N = 10;
const pii DELTA[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// variables
int N;
int mat[MAX_N][MAX_N];


void solution(){
   std::memset(mat, 0x00, sizeof(mat));

   int num = 0;
   int y = 0, x = 0, dir = 0;
   while(num < N * N){
      mat[y][x] = ++num;
      
      int nextY = y + DELTA[dir].second
         , nextX = x + DELTA[dir].first;
      if((nextY < 0 || N <= nextY || nextX < 0 || N <= nextX) 
         || mat[nextY][nextX] != 0){
         dir = (dir + 1) % 4;
         nextY = y + DELTA[dir].second;
         nextX = x + DELTA[dir].first;
      }
      y = nextY;
      x = nextX;
   }
}


int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;

      solution();

      std::cout << '#' << t << '\n';
      for(int y = 0; y < N; ++y){
         for(int x = 0; x < N; ++x){
            std::cout << mat[y][x] << ' ';
         }
         std::cout << '\n';
      }
   }

   return 0;
}