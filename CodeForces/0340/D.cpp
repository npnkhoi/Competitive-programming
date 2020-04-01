using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>

int n, x, l, r, mid;
vector<int> v;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d",&x);
        if (v.empty()) v.push_back(x);
        else if (x > v.back()) v.push_back(x);
        else
        {
            l = 0; r = v.size() - 1;
            while (l < r)
            {
                mid = (l+r) / 2;
                if (x < v[mid]) r = mid;
                else l = mid + 1;
            }
            v[l] = x;
        }
        /*for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;*/
    }
    cout << v.size();
}
