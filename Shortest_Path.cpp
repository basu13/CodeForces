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
ll v;
vector<int> edge[30000];
struct flag{
   public:
       int a,b,c;
};

bool operator < (flag f, flag s) {
  if (f.a != s.a) return f.a < s.a;
  if (f.b != s.b) return f.b < s.b;
  return f.c < s.c;
}

set<flag> st;
void addEdge(int u,int v)
{
    edge[u].pb(v);
    edge[v].pb(u);
}
void bfs(int s)
{
    int dis[v+1][v+1];
    for(int i=0;i<=v;i++)
        for(int j=0;j<=v;j++)
          dis[i][j]=-1;
    pair<int,int> p[v+1][v+1];
    queue<pair<int,int> > q;
    for(int i=0;i<edge[1].size();i++)
    {
        dis[1][edge[1][i]]=1;
        q.push(mpr(1,edge[1][i]));
    }
    while(!q.empty())
    {
        int a=q.front().fr;
        int b=q.front().sec;
        q.pop();
        for(int i=0;i<edge[b].size();i++)
        {
            int c=edge[b][i];
            if(dis[b][c]==-1 && st.find({a,b,c})==st.end())
                {
                    dis[b][c]=dis[a][b]+1;
                    q.push(mpr(b,c));
                    p[b][c]=mpr(a,b);
                }
        }
    }
    /*for(int i=0;i<=v;i++)
       {
           for(int j=0;j<=v;j++)
                cout<<dis[i][j]<<" ";
           cout<<"\n";
       }*/

    int fdis=INT_MAX,fcoo=0;
    for(int i=0;i<edge[v].size();i++)
    {
        int k=edge[v][i];
        if(dis[k][v]!=-1)
           {
                fdis=min(dis[k][v],fdis);
                if(fdis==dis[k][v])
                    fcoo=k;
           }

    }
    vector<int> path;
    if(fdis==INT_MAX)
        cout<<-1<<"\n";
    else
    {
        cout<<fdis<<"\n";
        int a=fcoo;
        int b=v;
        path.pb(b);
        path.pb(a);
        while(a!=1)
        {
            pair<int,int> pa=p[a][b];
            a=pa.fr;
            b=pa.sec;
            path.pb(a);
        }
        reverse(all(path));
        for(int i=0;i<path.size();i++)
            cout<<path[i]<<" ";
    }

}
int main()
{
    fast;
    long t;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>v;
        ll m,k;
        cin>>m>>k;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            addEdge(a,b);
        }
        for(int i=0;i<k;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            st.insert({a,b,c});
        }
        bfs(1);
        /*for(int i=0;i<v;i++)
        {
            cout<<"Edge "<<i<<"-> ";
            for(int j=0;j<edge[i].size();j++)
                cout<<edge[i][j]<<" ";
            cout<<"\n";
            cout<<"Flag "<<i<<"-> ";
            for(int j=0;j<flag[i].size();j++)
                cout<<flag[i][j]<<" ";
            cout<<"\n";
        }*/
    }

}

