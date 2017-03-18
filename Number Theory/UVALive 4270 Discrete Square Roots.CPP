/*
    UVALive 4270 Discrete Square Roots

　　在已知一个离散平方根的情况下，按照从小到大的顺序输出其他所有的离散平方根。

　　在模n意义下，非负整数x的离散平方根是满足0<=r<n且r2=x(mod n)的整数r。
  
    求解思路见http://www.cnblogs.com/from00/p/6574130.html
*/

#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;

set<ll> ans;
 ll x,n,r;

//扩展欧几里得算法
void gcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

void solve(ll a,ll b)
{
    ll k1,k2,d;
    gcd(a,b,d,k1,k2);

    if(2*r%d)
        return;

    k2*=(2*r/d);

    ll aa=a/d;
    k2%=aa;//k2是所有形如k2+k*aa的整数，最小的k2对应最小的r1

    ll r1=k2*b-r;
    while(r1<n)
    {
        if(r1>=0&&r1*r1%n==x)
            ans.insert(r1);

        r1+=aa*b;
    }
}

int main()
{
    int ca=0;
    while(~scanf("%lld%lld%lld",&x,&n,&r))
    {
        if(x==0&&n==0&&r==0)
            break;

        ans.clear();

        for(ll i=1;i*i<=n;i++)
            if(n%i==0)
            {
                 solve(i,n/i);
                 solve(n/i,i);
            }


        printf("Case %d: %lld",++ca,*ans.begin());
        for(set<ll>::iterator it=ans.begin();it!=ans.end();it++)
            if(it!=ans.begin())
            printf(" %lld",*it);
        printf("\n");
    }
    return 0;
}

