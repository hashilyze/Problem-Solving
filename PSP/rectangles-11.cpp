// 문제해결 기법 과제-11

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// === File Control ====
const std::string FILE_NAME = "rectangles";
const std::string INPUT_FILE = FILE_NAME + ".inp";
const std::string OUTPUT_FILE = FILE_NAME + ".out";

// === Solution ====
struct Triple {
    Triple() = default;
    Triple(int a, int b, int c) : a(a), b(b), c(c) { }

    int a, b, c;
};

int gcd(int a, int b) {
    if(a < b) std::swap(a, b);
    while(b != 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

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
    int i = 0, size = 300*300;
    std::vector<Triple> triples;
    triples.reserve(size);

    for(int mPn = 1; i < size; mPn += 2){
        for(int mNn = 1; i < size && mNn < mPn; mNn += 2){
            int m = (mNn + mPn) / 2;
            int n = mPn - m;

            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;

            if(gcd(a, b) == 1){
                triples.push_back({a, b, c});
                ++i;
            }
        }
    }
    std::sort(triples.begin(), triples.end(), [](const Triple& lhs, const Triple& rhs) { return (lhs.a + lhs.b) < (rhs.a + rhs.b); });

    int t;
    in >> t;
    while(t--){
        int cnt = 0, l;
        in >> l;
        
        for (auto beg = triples.cbegin(), end = triples.cend(); beg != end; ++beg) {
            if(l - (beg->a + beg->b) * 2 >= 0){
                l -= (beg->a + beg->b) * 2;
                ++cnt;
                continue;
            }
            break;
        }
        out << cnt << '\n';
    }
#ifndef ONLINE_JUDGE
    fin.close();
    fout.close();
#endif
    return 0;
}