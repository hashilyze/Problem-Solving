// [Beakjoon] 23350. K 물류창고

#include <iostream>
#include <list>
#include <queue>


#define FASTIO std::ios::sync_with_stdio(0); std::cin.tie(0);

using pii = std::pair<int, int>;

constexpr int MAX_N = 100;
constexpr int MAX_M = MAX_N;

int N, M;
int counts[MAX_M];
std::queue<pii> q;   // 레일
std::list<pii> stk;  // 적재 공간

int solution(){
    int cost = 0;
    int currentPriority = M - 1;
    while(!q.empty()){
        pii container = q.front(); // <priority, weight>
        q.pop();
        cost += container.second;  // 컨테이너는 적재되거나 레일의 처음으로 되돌아 감

        // 우선순위가 더 낮은 컨테이너가 있다면 처음으로 되돌림
        if(currentPriority != container.first) { 
            q.push(container);
            continue;
        }
        
        auto prevIt = --stk.end();
        auto curIt = stk.end();
        while(curIt != stk.begin() && prevIt->first == container.first && prevIt->second < container.second){
            cost += prevIt->second * 2;
            --prevIt;
            --curIt;
        }
        stk.insert(curIt, container);

        // 적재해야할 우선순위 갱신
        if(--counts[currentPriority] == 0) {
            --currentPriority;
        }
    }
    return cost;
}

int main(void) {
    FASTIO

    std::cin >> N >> M;
    for(int i = 0; i < N; ++i){
        int priority, weight;
        std::cin >> priority >> weight;
        ++counts[priority - 1];
        q.push({priority - 1, weight});
    }
    std::cout << solution();

    return 0;
}