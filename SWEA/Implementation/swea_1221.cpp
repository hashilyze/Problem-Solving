// [SWEA] 1221. [S/W 문제해결 기본] 5일차 - GNS

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 10'000;
std::map<std::string, int> toDigit({
   {"ZRO", 0}, {"ONE", 1}, {"TWO", 2}, {"THR", 3}, {"FOR", 4}
   , {"FIV", 5}, {"SIX", 6}, {"SVN", 7}, {"EGT", 8}, {"NIN", 9}
});
std::string toAlien[] = {
   "ZRO", "ONE", "TWO", "THR", "FOR", 
   "FIV", "SIX", "SVN", "EGT", "NIN"
};
// variables
int N;
int arr[MAX_N];


int main(int argc, char **argv) {
   FASTIO
   
   int T; std::cin >> T;
   //constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::string tmp;
      std::cin >> tmp >> N;
      for(int i = 0; i < N; ++i){
         std::cin >> tmp;
         arr[i] = toDigit[tmp];
      }

      std::sort(arr, arr + N);

      std::cout << '#' << t << '\n';
      for(int i = 0; i < N; ++i){
         std::cout << toAlien[arr[i]] << ' ';
      }
      std::cout << '\n';
   }

   return 0;
}