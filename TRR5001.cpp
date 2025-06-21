#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 	
			int n, s, t, a[1001][1001], used[1001], parent[1001]; vector<ii> ke[1001];
			void dijkstra(int s){
				priority_queue<ii, vector<ii>, greater<ii>> q;
				vector<int> d(n + 1, 1e9);
				d[s] = 0; q.push({0, s});
				while(!q.empty()){
					auto top = q.top(); q.pop();
					int u = top.second, dis = top.first;
					if(dis > d[u]) continue;
					for(auto e : ke[u]){
						int v = e.first, w = e.second;
						if(d[v] > d[u] + w){
							d[v] = d[u] + w;
							parent[v] = u;
							q.push({d[v], v});
						}
					}
		}
					if(d[t] != 10000){
						cout << d[t] << endl;
						vector<int> ans;
						while(t != s){
							ans.pb(t);
							t = parent[t];
						}
						ans.pb(t);
						reverse(ans.begin(), end(ans));
						for(int x : ans) cout << x << ' ';
					}
					else cout << 0;
				}
				int main(){
					freopen("DN.INP", "r", stdin);
					freopen("DN.OUT", "w", stdout);
					cin >> n >> s >> t;
					for(int i = 1; i <= n; i++){
						for(int j = 1; j <= n; j++){
							cin >> a[i][j];
							if(a[i][j] != 0 || a[i][j] != 10000) ke[i].pb({j, a[i][j]});
						}
					}
					dijkstra(s);
				}
