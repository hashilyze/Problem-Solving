// [SWEA] 21425. +=

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables


int solution(int A, int B, int N){
   int cnt = 0;
   while(A <= N && B <= N){
      ++cnt;
      if(A < B) A += B;
      else B += A;
   }
   return cnt;
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int A, B, N;
      std::cin >> A >> B >> N;
      std::cout << solution(A, B, N) << '\n';
   }

   return 0;
}