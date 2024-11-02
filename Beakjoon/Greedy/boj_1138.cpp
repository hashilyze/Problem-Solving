// Beakjoon 1138 - 한 줄로 서기
// https://www.acmicpc.net/problem/1138

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
int arr[10];

int main() { 
   FASTIO
   
   std::cin >> N;
   for(int i = 0; i < N; ++i){
      int elem;
      std::cin >> elem;

      int empty = 0;
      for(int j = 0; j < N; ++j){
         if(arr[j] == 0 && empty++ == elem) {
            arr[j] = i + 1;
            break;
         }
      }
   }
   for(int i = 0; i < N; ++i) std::cout << arr[i] << ' ';

   return 0; 
}