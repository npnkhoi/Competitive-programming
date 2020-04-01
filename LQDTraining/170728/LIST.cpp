using namespace std;
#include <stdio.h>
#include <queue>
#include <set>
priority_queue<int> pq;
set<int, greater<int> > data;

int main() {
    freopen("list.inp" ,"r", stdin);
    freopen("list.out" ,"w", stdout);
    char ch;
    while (scanf(" %c", &ch) != EOF) {
        if (ch == '+' && pq.size() < 15000) {
            int num;
            scanf("%d", &num);
            pq.push(num);
        }
        else if (ch == '-' && !pq.empty()) {
            int num = pq.top();
            while (!pq.empty() && pq.top() == num) pq.pop();
        }
    }

    while (!pq.empty()) {
        if (data.find(pq.top()) == data.end())
            data.insert(pq.top());
        pq.pop();
    }
    printf("%d\n", data.size());
    for (set<int>::iterator it = data.begin(); it != data.end(); it++)
    printf("%d\n", *it);

}
