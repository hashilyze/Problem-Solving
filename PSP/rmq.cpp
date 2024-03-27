// 문제해결 기법 과제-7

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

const std::string FILE_NAME = "rmq";
const std::string INPUT_FORMAT = ".inp";
const std::string OUTPUT_FORMAT = ".out";
const std::string INPUT_FILE = FILE_NAME + INPUT_FORMAT;
const std::string OUTPUT_FILE = FILE_NAME + OUTPUT_FORMAT;

struct Elem {
    Elem() = default;
    Elem(int index, long long min) : index(index), min(min) { }

    int index = 0;
    long long min = 0LL;
}; 

constexpr long long MAX = 9223372036854775807LL;
std::vector<long long> arr;
std::vector<Elem> rmq;

Elem initRmq(long long left, long long right, long long index){
    if(left == right) return rmq[index] = Elem(left, arr[left]);
    
    long long mid = (left + right) / 2;
    Elem leftMin = initRmq(left, mid, index * 2 + 1);
    Elem rightMin = initRmq(mid + 1, right , index * 2 + 2);
    return rmq[index] = (leftMin.min <= rightMin.min ? leftMin : rightMin);
}
Elem queryRmq(long long start, long long end, long long left, long long right, long long index){
    if(end < left || right < start) return Elem(1000001, MAX);
    if(start <= left && right <= end) return rmq[index];

    long long mid = (left + right) / 2;
    Elem leftMin = queryRmq(start, end, left, mid, index * 2 + 1);
    Elem rightMin = queryRmq(start, end, mid + 1, right, index * 2 + 2);
    return leftMin.min <= rightMin.min ? leftMin : rightMin;
}
Elem updateRmq(long long pos, long long val, long long left, long long right, long long index){
    if(pos < left || right < pos) return rmq[index];
    if(left == right) return rmq[index] = Elem(rmq[index].index, val);
    
    long long mid = (left + right) / 2;
    Elem leftMin = updateRmq(pos, val, left, mid, index * 2 + 1);
    Elem rightMin = updateRmq(pos, val, mid + 1, right , index * 2 + 2);
    return rmq[index] = (leftMin.min <= rightMin.min ? leftMin : rightMin);
}


int main(void){
#ifdef IO_ON_CONSOLE
    std::istream& in = std::cin;
    std::ostream& out = std::cout;
#else
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);

    std::istream& in = fin;
    std::ostream& out = fout;
#endif
    long long sum = 0L;
    long long n;
    in >> n;
    arr.resize(n);
    for(long long i = 0; i < n; ++i) in >> arr[i];
    rmq.resize(4 * n);
    initRmq(0, n - 1, 0);

    char command;
    long long a, b;
    while(in >> command >> a >> b){
        if(command == 's') break;

        switch(command){
        case 'c':{
            updateRmq(a, b, 0, n - 1, 0);
        } break;
        case 'q':{
            static constexpr long long MOD = 100000LL;
            int ret = queryRmq(a, b, 0, n - 1, 0).index;
            sum = ((sum % MOD) + (ret % MOD)) % MOD;
        } break;
        }
    }
    out << sum << '\n';
#ifndef IO_ON_CONSOLE
    fin.close();
    fout.close();
#endif
    return 0;
}