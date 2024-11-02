// Beakjoon 17615 - 볼 모으기
// https://www.acmicpc.net/problem/17615

#include <algorithm>
#include <iostream>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
// constants
// variables
int N;
char balls[500'001];


int solution(){
   int red = 0, blue = 0;
   for(int i = 0; i < N; ++i) {
      if(balls[i] == 'R') ++red;
      else ++blue;
   }
   
   int left = 0, right = 0;
   for(int i = 0; i < N; ++i) {
      if(balls[0] != balls[i]) break;
      left = i + 1;
   }
   left = (balls[0] == 'R' ? red : blue) - left;

   for(int i = N - 1; i >= 0; --i) {
      if(balls[N - 1] != balls[i]) break;
      right = N - i; // ((N - 1) - i) + 1
   }
   right = (balls[N - 1] == 'R' ? red : blue) - right;

   return std::min({red, blue, left, right});
}

int main() { 
   FASTIO

   std::cin >> N;
   std::cin >> balls;
   std::cout << solution();

   return 0; 
}