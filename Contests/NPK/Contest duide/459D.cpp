

using namespace std;


int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    id[b[0]]=0;
    m=0;
    for (int i=1;i<n;i++) if (b[i]!=b[i-1])
    {
        m++;
        id[b[i]]=m;
    }
    for (int i=0;i<n;i++) a[i]=id[a[i]];

    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<n;i++)
    {
        cnt[a[i]]++;
        ll[i]=cnt[a[i]]
    }
    memset(cnt,0,sizeof(cnt));
    for (int i=n-1;i>=0;i--)
    {
        cnt[a[i]]++;
        rr[i]=cnt[a[i]];
    }
}
