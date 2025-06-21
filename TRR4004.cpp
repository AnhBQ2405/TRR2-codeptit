#include<bits/stdc++.h>
#define ll long long
#define pi 3.141592654
#define mod 1000000007
#define ii pair<int, int>
#define iii pair<int, pair<int, int>> 
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int n, s, a[1001][1001], taken[1001]; vector<ii> ke[1001];
		struct canh{
			int u, v, w;
		};
		vector<canh> v;
		void prim(int s){
			taken[s] = 1;
			priority_queue<iii, vector<iii>, greater<iii>> q;
			for(auto e : ke[s]) q.push({e.second, {s, e.first}});
			int d = 0;
			while(!q.empty()){
				auto top = q.top(); q.pop();
				int w = top.first, u = top.second.second, par = top.second.first;
				if(!taken[u]){
					d += w;
					taken[u] = 1;
					v.pb({par, u, w});
					for(auto e : ke[u]){
						if(!taken[e.first]) q.push({e.second, {u, e.first}});
					}
				}
			}
			if(v.size() != n - 1) cout << 0;
			else{
				cout << d << endl;
				for(auto x : v) cout << min(x.u, x.v) << ' ' << max(x.u, x.v) << ' ' << x.w << endl;
			}
		}
		int main(){
		    freopen("CK.INP", "r", stdin);
		    freopen("CK.OUT", "w", stdout);
			cin >> n >> s;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					cin >> a[i][j];
					if(a[i][j] != 0 && a[i][j] != 1e4 && i < j){
						ke[i].pb({j, a[i][j]});
						ke[j].pb({i, a[i][j]});
					}
				}
			}
			prim(s);
		}
