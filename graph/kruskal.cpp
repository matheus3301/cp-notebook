#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << "\n"
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mxN = 100010;
const int mxM = 100010;

struct edge{
    int u,v,w;
};

bool ordena(edge a, edge b){
    return a.w < b.w;
}

edge ed[mxM];
int n,m;

int ans;

int pai[mxN],sz[mxN];

int find(int p){
    if(pai[p] == p) return p;
    return pai[p] = find(pai[p]);
}

void join(int p, int q){
    p = find(p);
    q = find(q);

    if(p == q) return;

    if(sz[p] > sz[q]) swap(p,q);
    pai[p] = q;
    sz[q] += sz[p];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        pai[i] = i;
        sz[i] = 1;
    }

    int u,v,w;
    edge tmp;
    for(int i = 0; i < m; i++){
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
    }

    sort(ed,ed+m,ordena);
    
    for(int i = 0; i < m; i++){
        if(find(ed[i].u) == find(ed[i].v)) continue;

        join(ed[i].u,ed[i].v);
        ans += ed[i].w;
    }

    cout << ans << endl;
    
    return 0;
}