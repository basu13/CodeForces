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
int n,m;
bool cat[1000005];
vector<int> adj[100005];
bool vis[100005];

int count(int s,int c)
{
    if(c>m)
        return 0;
    vis[s]=true;
    int res=0;
    int f=0;
    for(int i=0;i<adj[s].size();i++)
    {
        if(vis[adj[s][i]]==false)
        {
            f=1;
            if(cat[adj[s][i]]==true)
                res+=count(adj[s][i],c+1);
            else
                res+=count(adj[s][i],0);
        }
    }
    if(f==0 && c<=m)
        return 1;
    return res;
}
int dfs()
{
    int c;
    if(cat[1])
        c=1;
    else
        c=0;
    int tmp=count(1,c);
    return tmp;

}
int main()
{
    fast;
    long t;
    //cin>>t
    t=1;
    while(t--)
    {
       cin>>n>>m;
       memset(cat,false,sizeof(cat));
       for(int i=0;i<n;i++)
       {
           int ct;
           cin>>ct;
           if(ct)
            cat[i+1]=true;
       }
       for(int i=0;i<n-1;i++)
       {
           int u,v;
           cin>>u>>v;
           adj[u].pb(v);
           adj[v].pb(u);
       }
       int res=dfs();
       cout<<res;
    }

}
