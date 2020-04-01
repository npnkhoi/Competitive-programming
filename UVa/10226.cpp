
#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

int tc, n;
string str;
map<string, int> data;
int main()
{
    //freopen("10226.inp","r",stdin);
    //freopen("10226.out","w",stdout);
    scanf("%d\n\n", &tc);
    while (tc--)
    {
        n=0;
        data.clear();
        while (1)
        {
            getline(cin, str);
            if (str == "") break;
            if (data.count(str) == 0) data[str] = 1;
            else data[str] ++;
            n++;
        }
        for (map<string, int>::iterator i = data.begin(); i!=data.end(); i++)
        {
            printf("%s %.4f\n", ((string)i->first).c_str(), 100.0*i->second/n);
        }
        if (tc) printf("\n");
    }
}
