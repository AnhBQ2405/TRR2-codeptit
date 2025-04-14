#include<bits/stdc++.h>
#define ll long long
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int V, E, U, a[1001][1001], visited[1005], parent[1005], degree[1005], sz[1005]; set<int> ke[1005]; vector<int> EC, tke[1001];
		void dfs(int u){
			visited[u] = 1;
			for(int v : tke[u]){
				if(!visited[v]) dfs(v);
			}
		}
		void euler(int u){
			stack<int> st; 
			st.push(u);
			while(!st.empty()){
				int x = st.top();
				if(ke[x].size()){
					int y = *ke[x].begin();
					st.push(y);
					ke[x].erase(y);
					ke[y].erase(x);
				}
				else{
					st.pop();
					EC.pb(x);
				}
			}
		} 
		int main(){
			freopen("CT.INP", "r", stdin);
			freopen("CT.OUT", "w", stdout);
			int t; cin >> t;
				memset(degree, 0, sizeof(degree));
				memset(visited, 0, sizeof(visited));
				if(t == 1){
					cin >> V;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++){
						cin >> a[i][j];
						degree[i] += a[i][j];
						if(a[i][j]) tke[i].pb(j);
					}
				}
				int tplt = 0;
				for(int i = 1; i <= V; i++){
					if(!visited[i]){
						++tplt; dfs(i);
					}
				}
				if(tplt != 1){
					cout << 0;
					return 0;
				}
				else{
					int bac = 0;
				for(int i = 1; i <= V; i++){
					bac += degree[i] % 2;
				}
				if(bac == 0) cout << 1 << endl;
				else if(bac == 2) cout << 2 << endl;
				else cout << 0 << endl;
				}
			}
				else{
					cin >> V >> U;
					for(int i = 1; i <= V; i++){
						for(int j = 1; j <= V; j++){
							cin >> a[i][j];
							if(a[i][j]){
								ke[i].insert(j);
							}
						}
				}
					euler(U);
					reverse(begin(EC), end(EC));
					for(int x : EC) cout << x << ' ';
				}
		}
