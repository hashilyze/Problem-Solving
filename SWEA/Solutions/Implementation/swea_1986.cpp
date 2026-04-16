// [SWEA] 1986. 지그재그 숫자

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;

int solution(int n){
   int sum = 0;
   for(int i = 1; i <= n; ++i) {
      sum += i % 2 ? i : -i;
   }

   return sum;
}

int main(int argc, char **argv) {
   FASTIO

   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;
      std::cout << '#' << t << ' ' << solution(N) << '\n';
   }

   return 0;
}