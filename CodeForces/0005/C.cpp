using namespace std;
#include <iostream>
#include <stdio.h>
#include <map>
map<int, int> data;
map<int, int> :: iterator it;
int res, cnt, t;
string str;
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> str;
    data[0] = -1;
    res = 0; cnt = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') t++; else t--;
        //cout << t << endl;
        if (data.find(t) != data.end())
        {
            //cout << "*" << i-data[t] << endl;
            int pos = data[t];
            if (i - pos == res) cnt ++;
            else if (i - pos > res) res = i - data[t], cnt = 1;
            //cout << "--->" << res << endl;
        }   else data[t] = i;
        data.erase(data.upper_bound(t), data.end());
        //for (it = data.begin(); it!=data.end(); it++) cout << it->first << " ";
        //cout << endl;
        //cout << "--------------------\n";
    }
    cout << res <<  " " << cnt;
}
