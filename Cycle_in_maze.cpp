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
bool vis[1000][1000];
int d[1000][1000];
vector<string> v;
int valid(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m)
        return true;
    return false;
}
void path(int i,int j)
{
    queue<pair<int,int> > q;
    q.push(mpr(i,j));
    //d[i][j]=0;
    //memset(d,0,sizeof(d));
    //memset(vis,false,sizeof(vis));
    vis[i][j]=true;
    while(!q.empty())
    {
        i=q.front().fr;
        j=q.front().sec;
        q.pop();
        if(valid(i+1,j) && v[i+1][j]!='*' && vis[i+1][j]==false)
        {
            vis[i+1][j]=true;
            d[i+1][j]=d[i][j]+1;
            q.push(mpr(i+1,j));
        }
        if(valid(i,j+1) && v[i][j+1]!='*' && vis[i][j+1]==false)
        {
            vis[i][j+1]=true;
            d[i][j+1]=d[i][j]+1;
            q.push(mpr(i,j+1));
        }
        if(valid(i-1,j) && v[i-1][j]!='*' && vis[i-1][j]==false)
        {
            vis[i-1][j]=true;
            d[i-1][j]=d[i][j]+1;
            q.push(mpr(i-1,j));
        }
        if(valid(i,j-1) && v[i][j-1]!='*' && vis[i][j-1]==false)
        {
            vis[i][j-1]=true;
            d[i][j-1]=d[i][j]+1;
            q.push(mpr(i,j-1));
        }

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
      cin>>n>>m>>k;
      for(int i=0;i<n;i++)
      {
          string s;
          cin>>s;
          v.pb(s);
      }
      //for(int i=0;i<n;i++)
        //cout<<v[i]<<"\n";
        if(k&1)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        int x=-1,y=-1;
        for(int i=0;i<n;i++)
           {
             for(int j=0;j<m;j++)
                {
                   if(v[i][j]=='X')
                        {
                            x=i;
                            y=j;
                            break;
                        }
                }
                if(x!=-1)
                    break;
           }
        path(x,y);

       /* for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
               cout<<d[i][j]<<"-"<<vis[i][j]<<" ";
            cout<<"\n";
        }*/

        string res="";
        int sx=x,sy=y;
        bool flag=true;
        //cout<<res<<"\n";
        while(k && flag)
        {
            if(sx+1<n && vis[sx+1][sy] && k-d[sx+1][sy]>=0)
            {
                k--;
                sx++;
                res=res+'D';
                continue;
            }
            if(sy-1>=0 && vis[sx][sy-1] && k-d[sx][sy-1]>=0)
            {
                k--;
                sy--;
                res=res+'L';
                continue;
            }
            if(sy+1<m && vis[sx][sy+1] && k-d[sx][sy+1]>=0)
            {
                k--;
                sy++;
                res=res+'R';
                continue;
            }
            if(sx-1>=0 && vis[sx-1][sy] && k-d[sx-1][sy]>=0)
            {
                k--;
                sx--;
                res=res+'U';
                continue;
            }
            flag=false;
        }
        //cout<<flag<<"\n";
        if(!flag || k)
            cout<<"IMPOSSIBLE";
        else
             cout<<res;
      }
    }




