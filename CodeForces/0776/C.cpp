using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
int n, k, num;
long long res;
long long s;
vector <long long> v;
map<long long, int> sum;

int main()
{
    cin >> n >> k;
    //------------------------------
    if (k == 1) v.push_back(1);
    else if (k == -1) v.push_back(1), v.push_back(-1);
    else
        for (long long x = 1; abs(x) <= 2e14 + 50; x *= 1LL*k) v.push_back(x);
    //-------------------------------

    sum[0] = 1;
    while (n--)
    {
        cin >> num;
        s += 1LL * num;
        for (int j = 0; j < v.size(); j++)
            if (sum.find(s - v[j]) != sum.end()) res += sum[s-v[j]];
        if (sum.find(s) == sum.end()) sum[s] = 1;
            else sum[s] ++;
    }
    cout << res;
}
