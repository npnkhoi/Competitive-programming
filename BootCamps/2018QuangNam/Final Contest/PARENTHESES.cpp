// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================

string str;
char ch;
stack<char> s;
bool ans;
int tc;

bool ngoac_mo(char ch)
{
    return (ch=='(')||(ch=='[')||(ch=='{');
}
bool ok(char x, char y)
{
    return ((x=='(')&&(y==')'))
    ||((x=='[')&&(y==']'))||((x=='{')&&(y=='}'));
}
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    freopen("parentheses.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&tc);
    while (tc--)
    {
        cin>>str;
        ans=1;
        while (!s.empty()) s.pop();

        for (int i=0;i<str.size();i++)
        {
            if (ngoac_mo(str[i])) s.push(str[i]);
            else if (!s.empty()&&ok(s.top(),str[i]))
                s.pop();
                else
                {
                    printf("NO\n");
                    ans=0;
                    break;
                }
        }
        if (ans)
        {   if (s.empty()) printf("YES\n");
        else printf("NO\n");}
    }
    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
