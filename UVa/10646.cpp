#include <bits/stdc++.h>
#define ll long long
using namespace std;
int val(string s)
{
    if (isdigit(s[0])) return s[0]-48;
    else return 10;
}
int main()
{
    //freopen("10646.inp","r",stdin);
    //freopen("","w",stdout);
    int TC;
    scanf("%d",&TC);
    vector<string> deck;
    string new_card;
    for (int tc=1;tc<=TC;tc++)
    {
        deck.clear();
        for (int j=1;j<=52;j++)
        {
            cin>>new_card;
            deck.push_back(new_card);
        }
        int i=26, y=0, x;
        for (int j=1;j<=3;j++)
        {
            x=val(deck[i]);
            y+=x;
            x=11-x;
            while (x--)
                {
                    deck.erase(deck.begin()+i);
                    i--;
                }
        }
        printf("Case %d: %s\n",tc,deck[y-1].c_str());
    }
}
