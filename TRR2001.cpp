#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 	
			vector<int> ke[1001]; int a[1001][1001], V, E, S, T, visited[1001], parent[1001];
			void dfs(int u){
				visited[u] = 1;
				for(int v : ke[u]){
					if(!visited[v]){
						parent[v] = u;
						dfs(v);
					}
				}
			}
			int main(){
				fstream in, out;
				in.open("TK.INP", ios :: in);
				out.open("TK.OUT", ios :: out);
				int t; in >> t;
				in >> V >> S >> T;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++){
						in >> a[i][j];
						if(a[i][j]){
							ke[i].pb(j);
						}
					}
				}
				if(t == 1){
					int cnt = 0;
					for(int i = 1; i <= V; i++){
						if(a[S][i] && a[i][T]) ++cnt;
					}
					out << cnt << endl;
				}
				else{
					dfs(S);
					if(!visited[T]) out << 0;
					else{
						vector<int> v;
						while(T != S){
							v.pb(T);
							T = parent[T];
						}
						v.pb(S);
						reverse(begin(v), end(v));
						for(int x : v) out << x << ' ';
					}	
				}
			}
