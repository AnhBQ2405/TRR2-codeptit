#include<bits/stdc++.h>
#define ll long long
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int visited[1005], a[1001][1001], V; vector<int> dske[1005];
		void dfs(int u){
			visited[u] = 1;
			for(int v : dske[u]){
				if(!visited[v]){
					dfs(v);
				}
			}
		}
		int main(){
				freopen("TK.INP", "r", stdin);
				freopen("TK.OUT", "w", stdout);
				memset(visited, 0, sizeof(visited));
				cin >> V;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++){
						cin >> a[i][j];
						if(a[i][j]) dske[i].pb(j);
					}
				}
				int cnt = 0;
				for(int i = 1; i <= V; i++){
					if(!visited[i]){
						++cnt;
						dfs(i);
					}
				}
				vector<int> v;
				for(int i = 1; i <= V; i++){
					memset(visited, 0, sizeof(visited));
					visited[i] = 1;
					int dem = 0;
					for(int j = 1; j <= V; j++){
						if(!visited[j]){
							++dem;
							dfs(j);
						}
					}
					if(dem > cnt) v.pb(i);
				}
				sort(begin(v), end(v));
				cout << v.size() << endl;
				for(int x : v) cout << x << ' ';
			}

