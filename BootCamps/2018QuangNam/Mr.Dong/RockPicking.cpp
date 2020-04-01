
const int N=30;
int f[N][N][N][N][N];
int sol(int x[7])
{
    if (f[x[0]][x[1]][x[2]][x[3]][x[4]]>-1) return f[x[1]][x[2]][x[3]][x[4]][x[5]];
    t=0;
    for (int i=0;i<n;i++)
        if ((x[i]%2)&&(x[(i+1)%n]%2))
        {
            x[i]--; x[(i+1)%n]--;
            t+=sol(x[]);
            x[i]++; x[(i+1)%n]++;
        }
    for (int i=0;i<n;i++)
        if (x[i]&&x[(i+1)%2])
    {
        a=x[i]-x[i]/2;
        b=x[(i+1)%2]-x[(i+1)%n]/2;
        x[i]/=2;
        x[(i+1)%n]/=2;
        t+=sol(x[]);
        x[i]+=a; x[(i+1)%n]+=b;

    }

}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    x[0]=x[n];
    printf("%d",sol(x[0],x[1],x[2],x[3],x[4],x[5]));
}
