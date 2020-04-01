using namespace std;
#include <iostream>
const int md = 1e9+7;
string str;
int t,res,s;
int main()
{
    cin >> str;
    s = 0; t = 0;
    for (int i=0;i<str.size();i++)
    {
        if (str[i]=='a')
        {
            if (t) t = (t+t)%md; else t=1;
            s = (s+t)%md;
        }
        else res = (res+s)%md;
    }
    cout << res;
}
