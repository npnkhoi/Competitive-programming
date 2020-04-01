#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
char str[3];
int res,n;
string dir[7]={"","+x","+y","+z","-x","-y","-z"};
void change()
{
    if (str=="+y")
        switch(res)
    {
        case 1: res=2;
        case 2: res=4;
        case 4: res=6;
        case 5: res=1;
    }
    if (str=="-y")
    {
        if (res==1) res=5;
        if (res==5) res=4;
        case 4: res=2;
        case 2: res=1;
    }
    if (str=="+z")
        switch(res)
    {
        case 1: res=3;
        case 3: res=4;
        case 4: res=6;
        case 6: res=1;
    }
    if (str=="-z")
        switch(res)
    {
        case 1: res=6;
        case 6: res=4;
        case 4: res=3;
        case 3: res=1;
    }
}
int main()
{
while (1)
{
    res=1;
    scanf("%d",&n);
    if (n==0) break;
    res=1;
    while (--n)
    {
        scanf("%s",str);
        change();
        cout<<dir[res]<<endl;
    }
}
}
