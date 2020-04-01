int truyvet(int x)
{
    if (trace[x]!=-1) truyvet(trace[x]);
    printf("%d",x);
}
