#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char str[N];
int main() {
    scanf("%s", str);
    int n = strlen(str);
    int tmp = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    if (str[i] == '1') v.push_back(tmp), tmp = 0;
    else tmp ++;
    if (str[n-1] == '0') v.push_back(tmp);
    //for (int i = 0; i < v.size(); i++) cout << v[i] << endl;

    int sEven = 0, sOdd = 0;
    long long res = 0;
    for (int i = 0; i < v.size(); i++)
    if (i%2) {
        res += 1LL * v[i] * sEven;
        sOdd += v[i];
    } else {
        res += 1LL * v[i] * sOdd;
        sEven += v[i];
    }
    printf("%lld\n", res);
}
