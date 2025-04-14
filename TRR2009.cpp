#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
			int a[1001][1001], tplt[1001], visited[1001], cnt; vector<int> ke[1001];
			void dfs(int u){
				tplt[u] = cnt;
				visited[u] = 1;
				for(int v : ke[u]){
					if(!visited[v]) dfs(v);
				}
			}
			int main(){
				fstream in, out;
				in.open("TK.INP", ios :: in);
				out.open("TK.OUT", ios :: out);
				int n; in >> n;
				memset(visited, 0, sizeof(visited));
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++){
						in >> a[i][j];
						if(a[i][j]){
							ke[i].pb(j);
							ke[j].pb(i);
						}
					}
				}
				cnt = 0; 
				for(int i = 1; i <= n; i++){
					if(!visited[i]){
						++cnt;
						dfs(i);
					}
				}
				vector<int> v[cnt];
				out << cnt << endl; 
				for(int i = 1; i <= cnt; i++){
					for(int j = 1; j <= n; j++){
						if(tplt[j] == i) v[i - 1].pb(j);
					}
				}
				for(int i = 0; i < cnt; i++){
					for(int x : v[i]) out << x << ' ';
					out << endl;
				}
			}
