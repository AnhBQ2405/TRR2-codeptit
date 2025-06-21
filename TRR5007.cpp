#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
			int n, m, s, t, parent[1001]; 
			struct canh{
				int u, v, w;
			};
			vector<canh> edge;
			void bellmanford(int s){
				vector<int> d(n + 1, 1e9);
				d[s] = 0;
				for(int i = 1; i <= n - 1; i++){
					for(auto e : edge){
						if(d[e.v] > d[e.u] + e.w){
						d[e.v] = d[e.u] + e.w;
						parent[e.v] = e.u;
						}
					}
				}
				int ok = 1;
				for(auto e : edge){
					if(d[e.v] > d[e.u] + e.w){
						ok = 0; break;
					}
				}
				if(!ok) cout << -1;
				else{
					vector<int> ans;
					if(d[t] == 1e9) cout << 0 << endl;
					else{
						cout << d[t] << endl;
						while(t != s){
							ans.pb(t); t = parent[t];
						}
						ans.pb(t); reverse(begin(ans), end(ans));
						for(int x : ans) cout << x << ' ';
					}
				}
			}
			int main(){
					freopen("BN.INP", "r", stdin);
					freopen("BN.OUT", "w", stdout);
					cin >> n >> s >> t;
					for(int i = 1; i <= n; i++){
						for(int j = 1; j <= n; j++){
							int w; cin >> w;
							if(w != 0 && w != 10000){
								edge.pb({i, j, w});
//								edge.pb({j, i, w});
							}
						}
					}
					bellmanford(s);
			}
