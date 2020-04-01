
#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
char ch;
stack<int> st;
int x,y;
int main()
{
    //freopen("BITHU.inp","r",stdin);
    while (scanf(" %c",&ch)!=EOF)
    {
        if (ch>='A'&&ch<='Z') st.push(1);
        else
        {
            y=st.top();
            st.pop();
            x=st.top();
            st.pop();
            st.push(1+max(x,y));
        }
    }
    cout << st.top();
}
