#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int INF = 2e31;
const int mxN = 510;

int n,m;
char grid[mxN][mxN];
int dist[mxN][mxN];
int visited[mxN][mxN];


int mx[] = {0,0,1,-1};
int my[] = {1,-1,0,0};

priority_queue<pair<int,pair<int,int>>> q;


bool valido(int a, int b){
    if(a >= 0 && a < n && b >= 0 && b < m){
        return true;
    }else{
        return false;
    }
}

void dij(int i,int j){
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            dist[i][j] = INF;
        }
    }

    dist[i][j] = 0;

    q.push({0,{i,j}});

    while(!q.empty()){
        int ax = q.top().second.first;
        int ay = q.top().second.second;
        q.pop();

        if(visited[ax][ay]) continue;

        visited[ax][ay] = true;

        for(int mv = 0; mv < 4; mv++){
            int px = ax + mx[mv];
            int py = ay + my[mv];


            if(valido(px,py) && grid[px][py] != '#'){
                if(dist[ax][ay] + grid[px][py] - '0' < dist[px][py]){
                    dist[px][py] = dist[ax][ay] + grid[px][py] - '0';
                    q.push({-dist[px][py],{px,py}});
                }
            }
        }


    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int ii,ij;
    int fi,fj;
    char tmp;
    cin >> n >> m;

    for(int i = 0; i < n;i++){
        for(int j = 0; j < m; j++){
            cin >> tmp;
            if(tmp != '.'){
                grid[i][j] = tmp;
            }else{
                grid[i][j] = '0';
            }

            if(grid[i][j] == 'H'){
                ii = i;
                ij = j;
                grid[i][j] = '0';
            }

            if(grid[i][j] == 'E'){
                fi = i;
                fj = j;
                grid[i][j] = '0';

            }
        }
    }

    dij(ii,ij);

    if(dist[fi][fj] != INF){
        cout << dist[fi][fj] << endl;
    }else{
        cout << "ARTSKJID" << endl;
    }


    return 0;
}