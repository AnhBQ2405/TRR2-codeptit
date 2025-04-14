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
			fstream in, out;
			in.open("CT.INP", ios :: in);
			out.open("CT.OUT", ios :: out);
			in >> V >> U;
			for(int i = 1; i <= V; i++){
				for(int j = 1; j <= V; j++){
					in >> a[i][j];
					if(a[i][j]) ke[i].pb(j);
				}
			}
			hamilton(U, 1);
			if(v.size() == 0) out << 0;
			else{
				for(auto x : v){
					for(auto y : x) out << y << ' ';
					out << endl;
				}
				out << v.size();
			}
		}
