#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

int n, m, k, d[1000][1000], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool vs[1000][1000];
char g[1000][1000];

void go(int x, int y){
     vs[x][y] = true;
     queue<pair<int,int> > q;
     q.push({x, y});
     while(!q.empty()){
        x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i<4; ++i){
            int tx = x+dx[i], ty = y+dy[i];
            if(tx < 0 || ty < 0 || tx >= n || ty >= m || vs[tx][ty] || g[tx][ty] == '*')continue;
            vs[tx][ty] = true;
            d[tx][ty] = d[x][y]+1;
            q.push({tx, ty});
        }
     }
}

void no(){puts("IMPOSSIBLE"); exit(0);}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("read.txt","r",stdin);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    if(k & 1)no();
    int x , y, sx , sy;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin >> g[i][j];
            if(g[i][j] == 'X')x = i, y = j;
        }
    }
    go(x, y);
    sx = x, sy = y;
    string an = "";
    bool yes = true;
    while(k && yes){
       if(sx+1 < n && vs[sx+1][sy] && k - d[sx+1][sy] >= 0){an += 'D'; ++sx; --k; continue;}
       if(sy-1 >= 0 && vs[sx][sy-1] && k - d[sx][sy-1] >= 0){an += 'L'; --sy; --k; continue;}
       if(sy+1 < m && vs[sx][sy+1] && k - d[sx][sy+1] >= 0){an += 'R'; ++sy; --k; continue;}
       if(sx-1 >= 0 && vs[sx-1][sy] && k - d[sx-1][sy] >= 0){an += 'U'; --sx; --k; continue;}
       yes = false;
    }
    if(!yes || k)no();
    printf("%s\n", an.c_str());
}
