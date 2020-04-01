using namespace std;
#include <stdio.h>
#include <iostream>
#include <map>
#define task "KDIFF"
const int N = 3e5 + 50;


int n, k, a[N], maxL[N], l[N], r[N];
int res;
map<int, int> data;
void Push(int x) {
    if (data.find(x)==data.end())
        data[x] = 1;
    else data[x] ++;
}
void Pop(int x) {
    if (data[x] == 1) data.erase(x);
    else data[x] --;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d %d", &n, &k);
 
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
 
    l[1] = 1; Push(a[1]); maxL[1] = 1;
    for (int i = 2; i <= n; i++) {
        Push(a[i]);
        int j = l[i-1];
        for (; data.rbegin()->first - data.begin()->first > k; j++)
            Pop(a[j]);
        l[i] = j;
        maxL[i] = max(maxL[i-1], i-j+1);
        //cout << l[i] << " ";
    }
    /*cout << endl;
    for (int i = 1; i <= n; i++) cout << maxL[i] << " ";
    cout << endl;*/
    data.clear();
 
    r[n] = n; Push(a[n]);
    for (int i = n-1; i >= 1; i--) {
        Push(a[i]);
        int j = r[i+1];
        for (; data.rbegin()->first - data.begin()->first > k; j--)
            Pop(a[j]);
        r[i] = j;
        res = max(res, j-i+1 + maxL[i-1]);
        //cout << r[i] << " ";
    }
    //cout << endl;
    cout << res;
}