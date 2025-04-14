#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
			int a[1001][1001], tru[1001], low[1001], disc[1001], visited[1001], cnt, timer; vector<int> ke[1001]; vector<ii> edge;
			void dfs(int u, int par){
				visited[u] = 1;
				low[u] = disc[u] = ++timer;
				int child = 0;
				for(int v : ke[u]){
					if(v == par) continue;
					if(!visited[v]){
						dfs(v, u);
						++child;
						low[u] = min(low[u], low[v]);
						if(low[v] > disc[u]){
							edge.pb({u, v});
						}
					}
					else low[u] = min(low[u], disc[v]);
				}
			}
			int main(){
				fstream in, out;
				in.open("TK.INP", ios :: in);
				out.open("TK.OUT", ios :: out);
				int n; in >> n;
				memset(visited, 0, sizeof(visited));
				memset(tru, 0, sizeof(tru));
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++){
						in >> a[i][j];
						if(a[i][j] && i < j){
							ke[i].pb(j);
							ke[j].pb(i);
						}
					}
				} 
				timer = 0;
				for(int i = 1; i <= n; i++){
					if(!visited[i]){
						dfs(i, -1);
					}
				}
				out << edge.size() << endl;
				sort(begin(edge), end(edge));
				for(auto x : edge) out << x.first << ' ' << x.second << endl;
			}
