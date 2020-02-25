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

int main()
{
    fast;
    long t;
    cin>>t;
    while(t--)
    {
      ll n;
      cin>>n;
      string s;
      cin>>s;
      ll x=0,y=0;
      ll resx=-1,resy=-1,diff=999999;
      map<pair<int,int>,int> m;
      m[mpr(0,0)]=0;
      for(int i=0;i<n;i++)
      {
          if(s[i]=='L')
          {
              x--;
          }
          if(s[i]=='R')
          {
              x++;
          }
          if(s[i]=='U')
          {
              y++;
          }
          if(s[i]=='D')
          {
              y--;
          }
          pair<int,int> p=mpr(x,y);
              if(m.find(p)==m.end())
                  m[p]=i+1;
              else
              {
                  if(diff>i-m[p])
                  {
                      //cout<<m[p]<<"\n";
                      diff=i-m[p];
                      resx=m[p]+1;
                      resy=i+1;
                  }
                  m[p]=i+1;

              }
      }
      /*map<pair<int,int>,int>:: iterator it;
      for(it=m.begin();it!=m.end();it++)
      {
          cout<<it->fr.fr<<" "<<it->fr.sec<<" "<<it->sec<<"\n";
      }*/
      /*for(int i=0;i<=n;i++)
        cout<<p[i].fr<<" "<<p[i].sec<<"\n";


      for(int i=0;i<=n;i++)
      {
          for(int j=i+1;j<=n;j++)
          {
              if(p[i].fr==p[j].fr && p[i].sec==p[j].sec && diff>j-i)
              {
                  diff=j-i;
                  resx=i+1;
                  resy=j;
                  break;
              }
              if(diff<j-i)
                break;
          }
      }*/
      if(resx!=-1)
        cout<<resx<<" "<<resy<<"\n";
      else
        cout<<"-1\n";
    }

}





