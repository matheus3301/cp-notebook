#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << "\n"
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n,m;

vector<int> adj[100010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    
    int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    

    return 0;
}