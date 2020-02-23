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
vector<int> adj[300005];
int v;
map<pair<int,int>,int > mp;
int dis[300005];
void stations(int pol[],int k,int d)
{
    bool b[v+1];
    memset(b,false,sizeof(b));
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    for(int i=0;i<k;i++)
    {
        dis[pol[i]]=0;
        q.push(pol[i]);
    }
    vector<int> res;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        b[t]=true;
        for(int i=0;i<adj[t].size();i++)
        {
            int nod=adj[t][i];
            if(b[nod])
                continue;
            if(b[nod]==false && dis[nod]==-1)
            {
                q.push(nod);
                dis[nod]=dis[t]+1;
            }
            else
            {
                res.pb(mp[mpr(t,nod)]);
            }
        }
    }

    cout<<res.size()<<"\n";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";

}
int main()
{
    fast;
    long t;
    //cin>>t;
    t=1;
    while(t--)
    {
      int k,d;
      cin>>v>>k>>d;
      int pol[k];
      for(int i=0;i<k;i++)
        cin>>pol[i];

      /*cout<<k<<"\n";
	  for(int i=0;i<k;i++)
          cout<<pol[i]<<" ";
      cout<<"\n";*/

      sort(pol, pol + k);
	  k =unique(pol, pol + k)-pol;

	  /*cout<<k<<"\n";
	  for(int i=0;i<k;i++)
          cout<<pol[i]<<" ";
      cout<<"\n";*/

      for(int i=0;i<v-1;i++)
      {
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
          mp[mpr(u,v)]=i+1;
          mp[mpr(v,u)]=i+1;
      }
      /*for(int i=0;i<=v;i++)
      {
          for(int j=0;j<=v;j++)
            cout<<adj[i][j]<<" ";
          cout<<"\n";
      }*/
      stations(pol,k,d);

    }

}

