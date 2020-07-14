#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 2e31;
const int mxN = 10e5;

int n,m;


vector<int> adj[mxN];
int grau[mxN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        grau[b]++;
    }

    vector<int> ordenacao;
    for(int i = 1; i <= n; i++){
        if(grau[i] == 0){
            ordenacao.push_back(i);
        }
    }

    int j = 0;
    while(j < ordenacao.size()){
        int u = ordenacao[j];

        for(auto v : adj[u]){
            grau[v]--;
            if(grau[v] == 0){
                ordenacao.push_back(v);
            }
        }

        j++;
    }
    
    if(ordenacao.size() == n){
        cout << "S" << endl;

        for(auto i : ordenacao){
            cout << i << " ";
        }   
        cout << endl;
    }else{
        cout << "N" << endl;
    }
   
    return 0;
}