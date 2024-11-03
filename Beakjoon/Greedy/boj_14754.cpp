// Beakjoon 14754 - Pizza Boxes
// https://www.acmicpc.net/problem/14754

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ll = long long;
// constants
// variables
int N, M; 
int mat[1'000][1'000];
bool top[1'000][1'000];


ll solution(){
   // side view
   for(int y = 0; y < N; ++y){
      int maxPos = 0;
      for(int x = 0; x < M; ++x){
         if(mat[y][maxPos] < mat[y][x]) maxPos = x;
      }
      top[y][maxPos] = true;
   }
   // front view
   for(int x = 0; x < M; ++x){
      int maxPos = 0;
      for(int y = 0; y < N; ++y){
         if(mat[maxPos][x] < mat[y][x]) maxPos = y;
      }
      top[maxPos][x] = true;
   }
   

   ll sum = 0;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         if(!top[y][x]) sum += mat[y][x];
      }
   }
   return sum;
}

int main() { 
   FASTIO
   
   std::cin >> N >> M;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         std::cin >> mat[y][x];
      }
   }
   std::cout << solution();

   return 0; 
}