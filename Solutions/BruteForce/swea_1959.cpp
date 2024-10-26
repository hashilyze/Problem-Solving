// [SWEA] 1959. 두 개의 숫자열

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 20;
// variables
int N, M;
int arr1[SIZE], arr2[SIZE];


int solution(int lenA, int* arrA, int lenB, int* arrB){
   if(lenA > lenB) {
      std::swap(lenA, lenB);
      std::swap(arrA, arrB);
   }

   int max = 0x80000000;
   for(int i = 0; i < lenB - lenA + 1; ++i){
      int val = 0;
      for(int j = 0; j < lenA; ++j){
         val += arrA[j] * arrB[i + j];
      }
      max = std::max(max, val);
   }
   return max;
}

int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N >> M;
      for(int i = 0; i < N; ++i) std::cin >> arr1[i];
      for(int i = 0; i < M; ++i) std::cin >> arr2[i];
      std::cout << '#' << t << ' '
         << solution(N, arr1, M, arr2) << '\n';
   }

   return 0;
}