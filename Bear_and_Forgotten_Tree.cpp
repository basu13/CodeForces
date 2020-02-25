/*
author= @rp!t Jain
*/
#include<bits/stdc++.h>
#define mod 1000000007
#define fr first
#define sec second
#define ll long long
#define PI 3.1415926535
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

ll fac[200005];
void pre(){ fac[0]=1; fac[1]=1; for(int i=2;i<200005;i++) fac[i]=(i*fac[i-1])%mod;}
ll power(ll a,ll b){ll res=1;while(b){if(b&1) res=(res*a)%mod;a=(a*a)%mod;b=b/2;}return res%mod;}
ll ncr(ll n,ll r){return ((fac[n]*power(fac[r],mod-2))%mod*power(fac[n-r],mod-2))%mod;}
ll prime[2000005];
void soe()
{
    for(int i=0;i<2000005;i++)
        prime[i]=true;
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<2000005;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*2;j<2000005;j+=i)
               prime[j]=false;
        }
    }
}
int n,m,k;
set<pair<int,int> > s;
set<int> vis;
int valid(int i,int j)
{
    return s.count(mpr(min(i,j),max(i,j)))==0;
}
void dfs(int v)
{
    vector<int> adj;
    for(int i:vis)
       if(valid(v,i))
          adj.pb(i);
    for(int i=0;i<adj.size();i++)
        vis.erase(adj[i]);
    for(int i=0;i<adj.size();i++)
        dfs(adj[i]);
}
int find()
{
    int c=0;
    for(int i=2;i<=n;i++)
        {
            if(valid(1,i) && vis.count(i))
              {
                 vis.erase(i);
                 dfs(i);
                 c++;
              }
        }
     if(c>k || vis.size())
            return 0;
     return 1;
}
int main()
{
    fast;
    long t;
    //cin>>t;
    t=1;
    while(t--)
    {
       cin>>n>>m>>k;
       int deg=n-1;
       for(int i=0;i<m;i++)
       {
           int a,b;
           cin>>a>>b;
           if(a==1 || b==1)
              deg--;
           s.insert(mpr(min(a,b),max(a,b)));
       }
    for(int i=2;i<=n;i++)
        vis.insert(i);
    if(deg>=k)
    {
        //vis.erase(1);
        int f=find();
        if(f==0)
            cout<<"impossible";
        else
            cout<<"possible";
    }
    else
    {
        cout<<"impossible";
    }



    }

}

