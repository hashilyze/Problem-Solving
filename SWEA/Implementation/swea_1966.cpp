// [SWEA] 1966. 숫자를 정렬하자

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int MAX_N = 50;
// variables
int N;
int arr[MAX_N];

int main(int argc, char **argv) {
   FASTIO
   
   int T;
   std::cin >> T;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;
      for(int i = 0; i < N; ++i) std::cin >> arr[i];
      
      std::sort(arr, arr + N);

      std::cout << '#' << t << ' ';
      for(int i = 0; i < N; ++i) std::cout << arr[i] << ' ';
      std::cout << '\n';
   }

   return 0;
}