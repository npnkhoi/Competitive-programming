#include <stdio.h>
long long s[1001][1001];
int n,m,k,u,v,z,t;

long long value(int u,int v,int z,int t){
    return s[z][t]-s[z][v-1]-s[u-1][t]+s[u-1][v-1];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            scanf("%lld",&s[i][j]);
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    while (k--){
        scanf("%d%d%d%d",&u,&v,&z,&t);
        long long res=1000000000000,tmp=value(u,v,z,t);
        for (int type=0;type<2;type++){
            int d=(type==0)?(u):(v),c=(type==0)?(z-1):(t-1),g;
            while (d<=c){
                g=(d+c)/2;
                long long s=(type==0?value(u,v,g,t):value(u,v,z,g))*2-tmp;
                if (s>=0){
                    res=(s<res)?(s):(res);
                    c=g-1;
                } else {
                    res=(-s<res)?(-s):(res);
                    d=g+1;
                }
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
