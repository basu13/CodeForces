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
vector<vector<int> > adj;
vector<int> edge[300000];
int v;
bool pl[300000];
void bfs(bool b[],int s,int d,vector<int> &fil)
{
    b[s]=true;
    queue<int> q;
    //fil.pb(s);
    q.push(s);
    int dis=0;
    while(!q.empty() && dis<=d)
    {
        dis++;
        int t=q.front();
        fil.pb(t);
        q.pop();
        for(int i=1;i<=v;i++)
        {
            if(adj[t][i]!=0 && b[i]==false && pl[i]==false)
            {
                q.push(i);
                b[i]=true;
            }
        }
    }


}
void stations(int pol[],int k,int d)
{
    bool b[v+1];
    memset(b,false,sizeof(b));
    memset(pl,false,sizeof(pl));
    for(int i=0;i<k;i++)
    {
        pl[pol[i]]=true;
    }
    vector<int> res;
    for(int i=0;i<k;i++)
    {
        vector<int> fil;
        bfs(b,pol[i],d,fil);
        /*for(int j=0;j<fil.size();j++)
          cout<<fil[j]<<" ";
        cout<<"\n";*/
        for(int j=0;j<fil.size();j++)
        {
            int ch=fil[j];
            for(int x=1;x<=v;x++)
            {
                if(adj[ch][x]!=0 && b[x]==false)
                {
                    res.pb(adj[ch][x]);
                    adj[ch][x]=0;
                    adj[x][ch]=0;

                }
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
      for(int i=0;i<=v;i++)
      {
          vector<int> tmp;
          for(int j=0;j<=v;j++)
            tmp.pb(0);
          adj.pb(tmp);
      }
      for(int i=0;i<v-1;i++)
      {
          int u,v;
          cin>>u>>v;
          adj[u][v]=i+1;
          adj[v][u]=i+1;
          edge[u].pb(v);
          edge[v].pb(u);
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

