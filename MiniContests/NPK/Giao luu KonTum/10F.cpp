#include <bits/stdc++.h>
using namespace std;
int B,C,G,K;
int oo=-200000;
int a[5];
int f[42][42][42][42][5];
int l[5][5];
int res;
int cal(int b,int c, int g, int k, int x)
{
    if (!(b||c||g||k)) return 0;
    int tmp=0;
    if (b) tmp=max(f[b][c][g][k][0]+l[0][x],tmp);
    if (c) tmp=max(f[b][c][g][k][1]+l[1][x],tmp);
    if (g) tmp=max(f[b][c][g][k][2]+l[2][x],tmp);
    if (k) tmp=max(f[b][c][g][k][3]+l[3][x],tmp);
    return tmp;
}
int main()
{
    //freopen("10F.inp","r",stdin);
    scanf("%d%d%d%d",&B,&C,&G,&K);
    //cout<<B<<C<<G<<K<<endl;
    for (int i=0;i<4;i++) scanf("%d",&a[i]);
    //for (int i=0;i<4;i++) cout<<a[i]<<"\t";
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) scanf("%d",&l[i][j]);
    //for (int i=0;i<4;i++)
      //  for (int j=0;j<4;j++) cout<<l[i][j]<<"\t";
    for (int x=0;x<=3;x++) f[0][0][0][0][x]=0;

    for (int b=0;b<=B;b++)
    for (int c=0;c<=C;c++)
    for (int g=0;g<=G;g++)
    for (int k=0;k<=K;k++)
        {
            if (b) f[b][c][g][k][0]=a[0]+cal(b-1,c,g,k,0);
                else f[b][c][g][k][0]=oo;
            if (c) f[b][c][g][k][1]=a[1]+cal(b,c-1,g,k,1);
                else f[b][c][g][k][1]=oo;
            if (g) f[b][c][g][k][2]=a[2]+cal(b,c,g-1,k,2);
                else f[b][c][g][k][2]=oo;
            if (k) f[b][c][g][k][3]=a[3]+cal(b,c,g,k-1,3);
                else f[b][c][g][k][3]=oo;
        }
    res=0;
    for (int i=0;i<=3;i++) res= max(res,f[B][C][G][K][i]);
    printf("%d",res);

}
