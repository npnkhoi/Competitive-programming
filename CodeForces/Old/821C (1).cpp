#include <bits/stdc++.h>

using namespace std;
const int oo = 1e9;
stack<int> st;
int n, res, x, cur;
char str[10];
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d", &n);
    n += n;
    while (n--)
    {
        scanf("%s", &str);
        if (str[0] == 'a')
        {
            scanf("%d", &x);
            st.push(x);
        }
        else
        {
            cur ++;
            if (!st.empty())
		if  (st.top() != cur)
            {
                res ++;
                while (!st.empty()) st.pop();
            }	else st.pop();
        }
    }
    cout << res;

    return 0;
}
/*_min = oo;
    _max = 0;
    tmp = oo;
    while (n--)
    {
        scanf("%s", &str);
        if (str[0] == 'a')
        {
            scanf("%d",&x);
            tmp = min(tmp, x);
            _max = max(_max, x);
            v.push_back(x);
        }
            else
        {
            ok = 1;
            for (int i = 1; i < v.size(); i++)
                if (v[i-1]<v[i]) ok = 0;
            res += ( (_min < _max) || (!ok));
            _min = min(tmp, _min);
            tmp = oo; _max = 0;
            v.clear();
        }
    }
    cout << res;*/
