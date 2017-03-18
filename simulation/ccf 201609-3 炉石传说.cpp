/*
    ccf 201609-3 炉石传说
    http://www.cnblogs.com/from00/p/6574889.html
*/
#include<bits/stdc++.h>
using namespace std;

int n;
int ans;//胜负
struct role{int a,h;};//角色定义

vector<role>my,your;//双方战场

//召唤随从
void summon(vector<role>& v)
{
    int pos,h,a;
    scanf("%d%d%d",&pos,&a,&h);
    v.push_back({0,0});

    for(int i=v.size()-1;i>pos;i--)
        v[i]=v[i-1];

    v[pos]={a,h};
}

//随从死亡
void del(vector<role>& v,int pos)
{
    vector<role>::iterator it=v.begin();
    for(int i=0;i<pos;i++)
        it++;
    v.erase(it);
}

//攻击
void attack(vector<role>& v1,vector<role>& v2)
{
    int attacker,defender;
    scanf("%d%d",&attacker,&defender);

    v1[attacker].h-=v2[defender].a;
    v2[defender].h-=v1[attacker].a;

    if(v1[attacker].h<=0)
        del(v1,attacker);
    if(v2[defender].h<=0&&defender)
        del(v2,defender);
}

void output()
{
    printf("%d\n",ans);

    printf("%d\n",my[0].h);

    printf("%d",my.size()-1);
    for(int i=1;i<my.size();i++)
        printf(" %d",my[i].h);
    printf("\n");


    printf("%d\n",your[0].h);

    printf("%d",your.size()-1);
    for(int i=1;i<your.size();i++)
        printf(" %d",your[i].h);
    printf("\n");
}

int main()
{
    while(~scanf("%d",&n))
    {
        my.clear();
        your.clear();
        my.push_back({0,30});
        your.push_back({0,30});

        string str;
        bool myturn=true;//是否是先手回合
        ans=0;
       for(int i=0;i<n;i++)
       {
           cin>>str;
           if(str=="summon")
                summon(myturn?my:your);
            else if(str=="attack")
            {
                 attack(myturn?my:your,myturn?your:my);
                //判断英雄是否死亡
                 if(my[0].h<=0)
                    ans=-1;
                 if(your[0].h<=0)
                    ans=1;
            }
            else
                myturn=!myturn;
       }

       output();

    }
    return 0;
}

