// Beakjoon 1080 - 행렬
// https://www.acmicpc.net/problem/1080

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_SIZE = 50;
constexpr int REVERSE = 3;
// variables
int N, M;
char A[MAX_SIZE][MAX_SIZE];
char B[MAX_SIZE][MAX_SIZE];


inline void reverse(int x, int y){
   const char V[] = {'1', '0'};
   
   for(int dy = 0; dy < REVERSE; ++dy){
      for(int dx = 0; dx < REVERSE; ++dx){
         char &elemA = A[y + dy][x + dx];
         elemA = V[elemA - '0'];
      }
   }
}

int solution(){
   int cnt = 0;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         if(N - REVERSE < y || M - REVERSE < x){
            if(A[y][x] == B[y][x]) continue;
            else return -1;
         }

         if(A[y][x] != B[y][x]){
            ++cnt;
            reverse(x, y);
         }
      }
   }
   return cnt;
}

int main() { 
   FASTIO

   std::cin >> N >> M;
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         std::cin >> A[y][x];
      }
   }
   for(int y = 0; y < N; ++y){
      for(int x = 0; x < M; ++x){
         std::cin >> B[y][x];
      }
   }
   std::cout << solution();

   return 0; 
}