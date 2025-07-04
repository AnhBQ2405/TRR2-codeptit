#include<bits/stdc++.h>
#define ll long long
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int a[1001][1001], V, E, U, visited[1001]; vector<int> ke[1001], res; vector<vector<int>> v;
		void hamilton(int u, int cnt){
			res.pb(u);
			visited[u] = 1;
			if(cnt == V){
				for(int x : ke[u]){
					if(x == U){
						res.pb(U);
						v.pb(res);
						res.pop_back();
						break;
					}
				}
			}
			else{
				for(int v : ke[u]){
				if(!visited[v]){
					hamilton(v, cnt + 1);
					}
				}
			}
			visited[u] = 0;
			res.pop_back();
		}
		int main(){
			cin >> V >> U;
			for(int i = 1; i <= V; i++){
				for(int j = 1; j <= V; j++){
					cin >> a[i][j];
					if(a[i][j] != 0 && a[i][j] != 1e4) ke[i].pb(j);
				}
			}
			hamilton(U, 1);
			if(v.size() == 0) cout << 0;
			else{
				int ok;
				int smin = 1e9;
				for(int i = 0; i < v.size(); i++){
					int s = 0;
					for(int j = 0; j < v[i].size() - 1; j++) s += a[v[i][j]][v[i][j + 1]];
					if(smin > s){
						smin = s;
						ok = i;
					}
				}
				cout << smin << endl;
				for(int j = 0; j < v[ok].size(); j++){
					cout << v[ok][j] << ' ';
				}
			}
		}
