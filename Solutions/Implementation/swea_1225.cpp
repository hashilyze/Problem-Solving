// [SWEA] 1225. [S/W 문제해결 기본] 7일차 - 암호생성기

#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
constexpr int SIZE = 8;
constexpr int CYCLE = 5;
// variables
int arr[SIZE];


int solution(){
   int head = 0;
   int delta = 1;

   while(1){
      arr[head] = std::max(arr[head] - delta, 0);
      delta = delta % CYCLE + 1;
      head = (head + 1) % SIZE;
      if(arr[(head - 1 + SIZE) % SIZE] == 0) break;
   }
   return head;
}

int main(int argc, char **argv) {
   FASTIO
   
   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::cin >> t;
      for(int i = 0; i < SIZE; ++i) std::cin >> arr[i];

      int head = solution();

      std::cout << '#' << t << ' ';
      for(int i = 0; i < SIZE; ++i) std::cout << arr[(i + head) % SIZE] << ' ';
      std::cout << '\n';
   }

   return 0;
}