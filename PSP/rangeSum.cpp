// 문제해결 기법 과제-6

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string FILE_NAME = "rangeSum";
const std::string INPUT_FORMAT = ".inp";
const std::string OUTPUT_FORMAT = ".out";
const std::string INPUT_FILE = FILE_NAME + INPUT_FORMAT;
const std::string OUTPUT_FILE = FILE_NAME + OUTPUT_FORMAT;


std::vector<long long> arr;
std::vector<long long> rsq;

long long initRsq(long long left, long long right, long long index){
    if(left == right) return rsq[index] = arr[left];
    
    long long mid = (left + right) / 2;
    long long leftSum = initRsq(left, mid, index * 2 + 1);
    long long rightSum = initRsq(mid + 1, right , index * 2 + 2);
    return rsq[index] = leftSum + rightSum;
}
long long queryRsq(long long start, long long end, long long left, long long right, long long index){
    if(end < left || right < start) return 0;
    if(start <= left && right <= end) return rsq[index];

    long long mid = (left + right) / 2;
    long long leftSum = queryRsq(start, end, left, mid, index * 2 + 1);
    long long rightSum = queryRsq(start, end, mid + 1, right, index * 2 + 2);
    return leftSum + rightSum;
}
long long updateRsq(long long pos, long long val, long long left, long long right, long long index){
    if(pos < left || right < pos) return rsq[index];
    if(left == right) return rsq[index] = val;
    
    long long mid = (left + right) / 2;
    long long leftSum = updateRsq(pos, val, left, mid, index * 2 + 1);
    long long rightSum = updateRsq(pos, val, mid + 1, right , index * 2 + 2);
    return rsq[index] = leftSum + rightSum;
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
    long long n;
    in >> n;
    arr.resize(n);
    for(long long i = 0; i < n; ++i) in >> arr[i];
    rsq.resize(4 * n);
    initRsq(0, n - 1, 0);

    char command;
    long long a, b;
    while(in >> command >> a >> b){
        if(command == 'q') break;

        switch(command){
        case 'c':{
            updateRsq(a - 1, b, 0, n - 1, 0);
        } break;
        case 's':{
            out << queryRsq(a - 1, b - 1, 0, n - 1, 0) << '\n';
        } break;
        }
    }
    
#ifndef IO_ON_CONSOLE
    fin.close();
    fout.close();
#endif
    return 0;
}