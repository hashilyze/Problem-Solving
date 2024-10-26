// [SWEA] 1984. 중간 평균값 구하기

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 10;
// variables
int arr[SIZE];


int solution(){
   int sum = 0;
   int min = arr[0], max = arr[0];
   for(int i = 1; i < SIZE; ++i) {
      min = std::min(min, arr[i]);
      max = std::max(max, arr[i]);
   }

   int n = 0;
   for(int i = 0; i < SIZE; ++i) {
      if(arr[i] == min || arr[i] == max) continue;
      sum += arr[i];
      ++n;
   }

   return (double)sum / n + 0.5;
}

int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      for(int i = 0; i < SIZE; ++i) std::cin >> arr[i];
      std::cout << '#' << t << ' ' << solution() << '\n';
   }

   return 0;
}