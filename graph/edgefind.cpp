#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mxN = 1e5 + 1;
const int INF = 2e31;

int n,m;
vector<int> adj[mxN];

bool visited[mxN];

vector<int> tin,low;
int timer;
set<pair<int,int>> bridge; 

priority_queue<pair<int,int> > q;
int dist[mxN];

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);

            if (low[to] > tin[v]){
                bridge.insert({to,v});
                bridge.insert({v,to});
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void dij(int x){
    for(int i = 0; i <= n; i++){
        dist[i] = INF;
        visited[i] = false;
    }

    dist[x] = 0;
    q.push({0,x});


    while(!q.empty()){
        int a = q.top().second; q.pop();

        if(visited[a]) continue;
        visited[a] = true;

        for(auto u : adj[a]){
            int b = u;

            if(dist[a] + bridge.count({a,b}) < dist[b]){
                dist[b] = dist[a] +  bridge.count({a,b});
                q.push({-dist[b],b});
            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    find_bridges();

    dij(0);

    pair<int,int> maior;
    for(int i = 0 ; i < n; i++){
        if(dist[i] == INF) continue;
        if(dist[i] > maior.first){
            maior.first = dist[i];
            maior.second = i;
        }
    }

    dij(maior.second);

    int ans = 0;
    for(int i = 0 ; i < n; i++){
        if(dist[i] == INF) continue;
        ans = max(ans,dist[i]);
    }


    cout << ans << endl;

    return 0;
}