/*
    UVALive 4998	Simple Encryption
    输入正整数K1（K1<=5000）,找一个12位正整数K2使得K1^K2=K2(mod 1012)。
    求解思路见：http://www.cnblogs.com/from00/p/6663560.html
*/

#include<bits/stdc++.h>
using namespace std;

typedef  long long ll;

const ll MOD=1e12;

ll mul(ll a,ll b)
{
    ll ite=(1ll<<20)-1;
    return (a*(b>>20)%MOD*(1<<20)%MOD+a*(b&ite)%MOD)%MOD;
}

ll pow_mod(ll a,ll b)
{
    ll ret=1;

    while(b)
    {
        if(b&1)
            ret=mul(ret,a)%MOD;

        b>>=1;
        a=mul(a,a)%MOD;
    }
    return ret;
}


ll solve(ll n)
{
    ll x=1e12;
    while(1)
    {
        ll ans=pow_mod(n,x);
        if(ans==x)
            return ans;

        x=ans;
    }
}

int main()
{
    ll k1;
    int Case=0;
    while(scanf("%lld",&k1)&&k1)
    {
        ll k2=solve(k1);
        printf("Case %d: Public Key = %lld Private Key = %lld\n",++Case,k1,k2);
    }
    return 0;
}

