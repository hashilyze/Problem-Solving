// [SWEA] 1948. 날짜 계산기

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
const int BASES[12] = { 
   0, 31, 59, 90, 120, 151, 
   181, 212, 243, 273, 304, 334 
};
// variables


inline int toDay(int mm, int dd){ return BASES[mm - 1] + dd - 1; }
inline int solution(int mm1, int dd1, int mm2, int dd2){
   return toDay(mm2, dd2) - toDay(mm1, dd1) + 1;
}

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      int mm1, dd1, mm2, dd2;
      std::cin >> mm1 >> dd1 >> mm2 >> dd2;
      std::cout << '#' << t << ' ' << solution(mm1, dd1, mm2, dd2) << '\n';
   }

   return 0;
}