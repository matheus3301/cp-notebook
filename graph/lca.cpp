#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 2E31;
const int mxL = 18;
const int mxN = 1e5 + 10;


vector<ii> adj[mxN];
int pai[mxN];
int nivel[mxN];
ll dist[mxN];
int ancestral[mxN][mxL];

int n,m;

void dfs(int u){
    
    for(auto b : adj[u]){
        int v = b.first;
        int w = b.second;

        if(nivel[v] == -1){
			pai[v] = u;
			nivel[v] = nivel[u]+1;
            dist[v] = (dist[u] + w)*1LL;
			
			dfs(v);
		}
    }
		
}

int LCA(int u, int v){
	
	if(nivel[u] < nivel[v]) swap(u, v);
	
	for(int i = mxL-1;i >= 0;i--)
		if(nivel[u] - (1<<i) >= nivel[v])
			u = ancestral[u][i];
	
	if(u == v) return u;
	
	for(int i = mxL-1;i >= 0;i--)
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
			
	return pai[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while(n){
        int a,b;
        for(int i = 1; i < n; i++){
            cin >> a >> b;
            adj[i].push_back({a,b});
            adj[a].push_back({i,b});
        }

        for(int i = 0; i < n; i++) pai[i] = nivel[i] = -1;
        for(int i = 0; i < mxN; i++){
            for(int j = 0; j < mxL; j++){
                ancestral[i][j] = -1;
            }
        }

        nivel[0] = 0;
        dfs(0);

        for(int i = 0; i < n; i++){
            ancestral[i][0] = pai[i];
        }

        for(int j = 1; j < mxL; j++){
            for(int i = 0; i < n; i++){
                if(ancestral[i][j-1] != -1)
                    ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
            }
        }

        int q;
        cin >> q;

        while(q--){
            cin >> a >> b;
            

            cout << -2*dist[LCA(a,b)] + dist[a] + dist[b] << " ";
        }
        cout << endl;

        for(int i = 0; i < n; i++){
            adj[i].clear();
        }

        cin >> n;

    }

    
   
    return 0;
}