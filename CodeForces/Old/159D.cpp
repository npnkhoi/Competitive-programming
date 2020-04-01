#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>

//using namespace std;
const int N=2010;
char str[N];
int l,r,mid;
int left[N],right[N];
long long res;

int main()
{
    scanf("%s",&str);
    //std::cout << str;
    int n=strlen(str);
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
    for (int mid=0;mid<n;mid++)
    {
        l=mid; r=mid;
        while (l>=0&&r<n&&str[l]==str[r])
        {
            left[r]++;
            right[l]++;
            l--;
            r++;
        }
        l=mid; r=mid+1;
        while (l>=0&&r<n&&str[l]==str[r])
        {
            left[r]++;
            right[l]++;
            l--;
            r++;
        }
    }
    //for (int i=0;i<n;i++) std::cout << left[i] << " " << right[i] << std::endl;
    for (int i=0;i<n-1;i++)
    for (int j=i+1;j<n;j++)
    res+=left[i]*right[j];
    std::cout << res;
}
