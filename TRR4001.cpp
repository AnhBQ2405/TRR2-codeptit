#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 	
		int n, m, s, used[1001], a[1001][1001]; set<int> ke[1001]; vector<ii> res;
		void dfs(int u){
			used[u] = 1;
		for(int v : ke[u]){
				if(!used[v]){
				    if(u < v) res.pb({u, v});
					else res.pb({v, u});
					dfs(v);
				}
			}
		}
		void bfs(int u){
			queue<int> q; q.push(u);
			used[u] = 1;
			while(!q.empty()){
				u = q.front(); q.pop();
				for(int v : ke[u]){
					if(!used[v]){
						if(u < v) res.pb({u, v});
					else res.pb({v, u});
						q.push(v); used[v] = 1;
					}
				}
			}
		}
		int main(){
		    freopen("CK.INP", "r", stdin);
		    freopen("CK.OUT", "w", stdout);
		    memset(used, 0, sizeof(used));
			int t; cin >> t;
			cin >> n >> s;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					cin >> a[i][j];
					if(a[i][j]){
						ke[i].insert(j);
					}
				}
			}
			if(t == 1){
				dfs(s);
				if(res.size() != n - 1) cout << "0" << endl;
				else{
				    // sort(begin(res), end(res));
					cout << res.size() << endl;
					for(auto x : res) cout << x.first << ' ' << x.second << endl;
				}
			}
			else{
				bfs(s);
				if(res.size() != n - 1) cout << "0" << endl;
				else{
				    // sort(begin(res), end(res));
					cout << res.size() << endl;
					for(auto x : res) cout << x.first << ' ' << x.second << endl;
				}
			}
		}
