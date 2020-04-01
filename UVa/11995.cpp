using namespace std;
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
stack<int> st;
queue<int> q;
priority_queue<int> pq;
bool _st, _q, _pq;
int x,n;
void sol1()
{
    scanf("%d",&x);
    st.push(x);
    q.push(x);
    pq.push(x);
    //cout << 1 << endl;
}
void sol2()
{
    scanf("%d",&x);

    if (!st.empty())
    {
        if (_st && st.top()!=x) _st=0;
        if (_q && q.front()!=x) _q=0;
        if (_pq && pq.top()!=x) _pq=0;
        st.pop(); q.pop(); pq.pop();
    }
    else _st = _q = _pq = 0;
    //cout << 2 << endl;
}
void ans()
{
    int res = (int) _st + _q + _pq;
    if (res > 1) printf("not sure\n");
    else if (res == 0) printf("impossible\n");
    else
    {
        if (_st) printf("stack\n");
        else if (_q) printf("queue\n");
        else printf("priority queue\n");
    }
}
int main()
{
    //freopen("test.inp","r",stdin);
    while (scanf("%d",&n)!=EOF)
    {
        while (!st.empty()) st.pop();
        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
        _st = _q = _pq = 1;
        //-------------------
        int cmd;
        while (n--)
        {
            scanf("%d",&cmd);
            if (cmd == 1) sol1();
            else sol2();
        }
        ans();
    }
}
