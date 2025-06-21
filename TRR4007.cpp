#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 	
		int n, m, s, parent[1001], sz[1001];
		void init(){
			for(int i = 1; i <= n; i++){
				parent[i] = i;
				sz[i] = 1;
			}
		}
		int find(int u){
			if(u == parent[u]) return u;
			return parent[u] = find(parent[u]);
		}
		bool dsu(int u, int v){
			u = find(u);
			v = find(v);
			if(u == v) return false;
			if(sz[u] < sz[v]){
				parent[u] = v;
				sz[v] += sz[u];
			}
			else{
				parent[v] = u;
				sz[u] += sz[v];
			}
			return true;
		}
		struct canh{
			int x, y, z;
		};
		bool cmp(canh a, canh b){
			if(a.z == b.z && a.x == b.x) return a.y < b.y;
			else if(a.z == b.z) return a.x < b.x;
			return a.z < b.z;
		}
		vector<canh> v, ans;
		void kruskal(){
			sort(begin(v), end(v), cmp);
			int d = 0;
			for(auto e : v){
				if(ans.size() == n - 1) break;
				if(dsu(e.x, e.y)){
				d += e.z;
				ans.pb(e);
				}
			}
		    if(ans.size() != n - 1) cout << 0;
		    else{
		        	cout << d << endl;
			for(auto x : ans) cout << x.x << ' ' << x.y << ' ' << x.z << endl;
		    }
		}
		int main(){
		    freopen("CK.INP", "r", stdin);
		    freopen("CK.OUT", "w", stdout);
			cin >> n >> m;
			init();
			while(m--){
				int x, y, z;
				cin >> x >> y >> z;
				v.pb({x, y, z});
			}
			kruskal();
		}
