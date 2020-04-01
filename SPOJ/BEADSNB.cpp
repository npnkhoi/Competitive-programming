using namespace std;
#include <bits/stdc++.h>
const int N = 1e5 + 10;
int n, num, pos, tmp, res, a[N];
vector<int> lis, lds;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = n-1; i >= 0; i--){
        num = a[i];
        if (lis.empty() || num > lis.back()) {
            pos = lis.size();
            lis.push_back(num);
        }
        else {
            pos = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
            lis[pos] = num;
        }
        tmp = pos;
        //for (int j = 0; j < lis.size(); j++) cout << lis[j] << " "; cout << endl;
        num = -num;
        if (lds.empty() || num > lds.back()) {
            pos = lds.size();
            lds.push_back(num);
        } else {
            pos = lower_bound(lds.begin(), lds.end(), num) - lds.begin();
            lds[pos] = num;
        }
        //for (int j = 0; j < lds.size(); j++) cout << lds[j] << " "; cout << endl;
        tmp += 1+pos;
        res = max(res, tmp);
    }
    printf("%d", res);
}
