#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 	
			vector<int> ke[1001]; int a[1001][1001], b[1001][1001], V, E, S, T, visited[1001], parent[1001];
			void bfs(int u){
				queue<int> q;
				visited[u] = 1; q.push(u);
				while(!q.empty()){
					int u = q.front(); q.pop();
					for(int v : ke[u]){
						if(!visited[v]){
							parent[v] = u;
							q.push(v);
							visited[v] = 1;
						}
					}
				}
			}
			int main(){
				freopen("TK.INP", "r", stdin);
				freopen("TK.OUT", "w", stdout);
				int t; cin >> t;
				cin >> V >> S >> T;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++){
						cin >> a[i][j];
						if(a[i][j]){
							ke[i].pb(j);
						}
					}
				}
				if(t == 1){
					int cnt = 0;
					for(int i = 1; i <= V; i++){
						for(int j = 1; j <= V; j++){
						    int tmp = 0;
						    for(int k = 1; k <= V; k++){
						        tmp = tmp + (a[i][k] * a[k][j]);
						    }
						    b[i][j] = tmp;
						}
					}
					cout << b[S][T] << endl;
				}
				else{
				    memset(visited, 0, sizeof(visited));
				    memset(parent, 0, sizeof(parent));
					bfs(S);
					if(!visited[T]) cout << "0";
					else{
						vector<int> v;
						while(S != T){
							v.pb(T);
							T = parent[T];
						}
						v.pb(S);
						reverse(begin(v), end(v));
						for(int x : v) cout << x << ' ';
					}	
				}
			}
