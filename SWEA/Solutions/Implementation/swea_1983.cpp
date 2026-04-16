// [SWEA] 1983. 조교의 성적 매기기

#include <iostream>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int MAX_N = 100;
const std::string GRADE[] = {
   "A+", "A0", "A-", 
   "B+", "B0", "B-", 
   "C+", "C0", "C-", 
   "D0"
};
// variables
int N, K;
int scores[MAX_N];


inline int getScore(int a, int b, int c){ return a * 35 + b * 45 + c * 20; }

int getRank(int n, int k){
   int rank = 0;
   for(int i = 0; i < n; ++i){
      if(i == k || scores[i] <= scores[k]) continue;
      ++rank;
   }
   return rank;
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N >> K;

      int a, b, c;
      for(int i = 0; i < N; ++i){
         std::cin >> a >> b >> c;
         scores[i] = getScore(a, b, c);
      }

      std::cout << '#' << t << ' ' << GRADE[getRank(N, K - 1) / (N / 10)] << '\n';
   }

   return 0;
}