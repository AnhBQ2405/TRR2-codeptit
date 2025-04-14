#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
			int a[1001][1001], tplt[1001], visited[1001], cnt; vector<int> ke[1001], tke[1001], ke1[1001]; stack<int> st;
			void dfs1(int u){
				visited[u] = 1;
				for(int v : ke[u]){
					if(!visited[v]) dfs1(v);
				}
				st.push(u);
			}
			void dfs2(int u){
				visited[u] = 1;
				for(int v : tke[u]){
					if(!visited[v]) dfs2(v);
				}
			}
			void dfs3(int u){
				visited[u] = 1;
				for(int v : ke1[u]){
					if(!visited[v]) dfs3(v);
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
							tke[j].pb(i);
							ke1[i].pb(j);
							ke1[j].pb(i);
						}
					}
				} 
				for(int i = 1; i <= n; i++){
					if(!visited[i]){
						dfs1(i);
					}
				}
				memset(visited, 0, sizeof(visited));
				int scc = 0;
				while(!st.empty()){
					int u = st.top(); st.pop();
					if(!visited[u]){
						++scc;
						dfs2(u);
					}
				}
				if(scc == 1) out << 1;
				else{
					memset(visited, 0, sizeof(visited));
					int cnt = 0;
					for(int i = 1; i <= n; i++){
						if(!visited[i]){
							++cnt;
							dfs3(i);
						}
					}
					if(cnt == 1) out << 2;
					else out << 0;
				}
			}
