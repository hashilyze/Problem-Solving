// [SWEA] 1230. [S/W 문제해결 기본] 8일차 - 암호문3

#include <iostream>
#include <list>
#include <vector>

// macros
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// types
using ivec = std::vector<int>;
// constants
// variables
int N, K;
std::list<int> C;


void do_insert(int x, int y, const ivec& s){
   auto it = C.begin();
   for(int i = 0; i < x; ++i) ++it;
   C.insert(it, s.begin(), s.end());
}

void do_delete(int x, int y){
   auto first = C.begin(), last = C.begin();
   for(int i = 0; i < x; ++i) ++first;
   for(int i = 0; i < x + y; ++i) ++last;

   C.erase(first, last);
}

void do_append(int y, const ivec& s){
   C.insert(C.end(), s.begin(), s.end());
}

int main(int argc, char **argv) {
   FASTIO

   //int T; std::cin >> T;
   constexpr int T = 10;
   for(int t = 1; t <= T; ++t){
      std::cin >> N;
      
      C.clear();
      for(int i = 0; i < N; ++i){
         int e;
         std::cin >> e;
         C.push_back(e);
      }

      std::cin >> K;
      for(int i = 0; i < K; ++i){
         char cmd;
         std::cin >> cmd;
         
         if(cmd == 'I'){
            int x, y;
            std::cin >> x >> y;

            ivec s;
            for(int j = 0; j < y; ++j){
               int e;
               std::cin >> e;
               s.push_back(e);
            }
            do_insert(x, y, s);
         } else if(cmd == 'D'){
            int x, y;
            std::cin >> x >> y;
            do_delete(x, y);
         } else if(cmd == 'A'){
            int y;
            std::cin >> y;

            ivec s;
            for(int j = 0; j < y; ++j){
               int e;
               std::cin >> e;
               s.push_back(e);
            }

            do_append(y, s);
         }
      }
      
      std::cout << '#' << t << ' ';
      auto it = C.begin();
      for(int i = 0; i < 10; ++i){
         std::cout << *it++ << ' ';
      }
      std::cout << '\n';
   }

   return 0;
}