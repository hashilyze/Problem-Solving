// 문제해결기법 과제-21

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <functional>


// === File Control ====
const std::string FILE_NAME = "add";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";
// types
using ll = long long;
using minHeap = std::priority_queue<ll, std::vector<ll>, std::greater<ll>>;

int main(void){
#ifndef ONLINE_JUDGE
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);
    std::istream& in = fin;
    std::ostream& out = fout;
#else
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#endif
    int n;
    while(in >> n){
        if(n == 0) break;

        minHeap heap;
        for(int i = 0; i < n; ++i) {
            int input;
            in >> input;
            heap.push(input);
        }

        ll sum = 0;
        while(heap.size() > 1){
            ll lhs = heap.top(); heap.pop();
            ll rhs = heap.top(); heap.pop();
            sum += lhs + rhs;
            heap.push(lhs + rhs);
        }
        out << sum << '\n';
    }


#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}