using namespace std;
#include <stdio.h>
#include <iostream>
int h,m,remain,res;
string str;
bool ok()
{
    /*if (h<10) return (m/10 == h && (m%10 == 0));
        else*/
    return (10*(m%10) + m/10) == h;
}
int main()
{
    cin>>str;
    h = 10*(str[0]-'0')+str[1]-'0';
    m = 10*(str[3]-'0')+str[4]-'0';
    //  cout << h << " " << m <<endl;
    res = 0;
    while (!ok())
    {
        res ++;
        remain = (m==59);
        m = (m+1)%60;
        h = (h+remain)%24;
        //cout << h << " " << m << " " << res << endl;
    }
    cout << res;
}
