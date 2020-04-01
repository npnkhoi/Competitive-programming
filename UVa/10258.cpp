using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
struct rc
{
    int solved, pen, id;
};
int tc;
int data[110][11];
bool ac[110][11];
bool join[110];
char line[20];
vector<rc> v;

bool cmp(rc a, rc b)
{
   if (a.solved!=b.solved)
    return a.solved>b.solved;
   else if (a.pen!=b.pen)
    return a.pen<b.pen;
    else return a.id<b.id;
}
int main()
{
    //freopen("10258.inp","r",stdin);
    //freopen("10258.out","w",stdout);
    scanf("%d\n\n",&tc);
    while (tc--)
    {
        memset(data,0,sizeof(data));
        memset(join,0,sizeof(join));
        memset(ac,0,sizeof(ac));
        v.clear();
        while (gets(line))
        {
            //cout << line << endl;
            if (!strcmp(line,"")) break;
            int team, prob, time;
            char verd;
            sscanf(line,"%d %d %d %c",&team,&prob,&time,&verd);
            if (ac[team][prob]) continue;
            join[team]=1;
            if (verd=='I') data[team][prob]+=20;
            if (verd=='C')
            {
                data[team][prob] += time;
                ac[team][prob]=1;
            }
        }
        //-------------------------------
        for (int i=1;i<=100;i++) if (join[i])
        {
            int _solved=0, _pen=0;
            for (int j=1;j<=9;j++) if (ac[i][j])
            {
                _solved++;
                _pen+=data[i][j];
            }
            rc t;
            t.solved=_solved;
            t.pen=_pen;
            t.id=i;
            v.push_back(t);
        }
        sort(v.begin(),v.end(),cmp);
        for (int i=0;i<v.size();i++) printf("%d %d %d\n",v[i].id,v[i].solved,v[i].pen);
        if (tc) printf("\n");
    }
}
