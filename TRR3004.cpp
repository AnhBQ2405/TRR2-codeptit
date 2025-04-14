#include<bits/stdc++.h>
#define ll long long
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int V, E, U, visited[1005], parent[1005], in[1005], out[1005], a[1005][1005]; set<int> ke[1005], tke[1005]; vector<int> EC; stack<int> s;
		void dfs(int u){
			visited[u] = 1;
			for(int v : ke[u]){
				if(!visited[v]) dfs(v);
			}
			s.push(u);
		}
		void dfs2(int u){
			visited[u] = 1;
			for(int v : tke[u]){
				if(!visited[v]) dfs2(v);
			}
		}
		void euler(int u){
			stack<int> st; 
			st.push(u);
			while(!st.empty()){
				int x = st.top();
				if(ke[x].size()){
					int y = *ke[x].begin();
					st.push(y);
					ke[x].erase(y);
				}
				else{
					st.pop();
					EC.pb(x);
				}
			}
		} 
		int main(){
			freopen("CT.INP", "r", stdin);
			freopen("CT.OUT", "w", stdout);
			int t; cin >> t;
			memset(visited, 0, sizeof(visited));
			memset(in, 0, sizeof(in));
			memset(out, 0, sizeof(out));
			if(t == 1){
				cin >> V;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++){
						cin >> a[i][j];
						if(a[i][j]){
							ke[i].insert(j);
							tke[j].insert(i);
							in[j]++; out[i]++;
						}
					}
				}
				
				for(int i = 1; i <= V; i++){
					if(!visited[i]){
						dfs(i);
					}
				}
				int tplt = 0;
				memset(visited, 0, sizeof(visited));
				while(!s.empty()){
					int u = s.top(); s.pop();
					if(!visited[u]){
						++tplt;
						dfs2(u);
					}
				}
				if(tplt != 1){
					cout << 0;
					return 0;
				}
				else{
					int cnt1 = 0, cnt2 = 0;
				for(int i = 1; i <= V; i++){
					if(in[i] != out[i]){
					    if(in[i] - out[i] == 1) cnt1++;
					    else if(out[i] - in[i] == 1) cnt2++;
					    else{
					    	cout << 0;
					    	return 0;
						}
					}
				}
				if(cnt1 == 0 && cnt2 == 0) cout << 1 << endl;
				else if(cnt1 == 1 && cnt2 == 1) cout << 2 << endl;
				else cout << 0 << endl;
			}
				}
			else{
				cin >> V >> U;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++){
						cin >> a[i][j];
						if(a[i][j]) ke[i].insert(j);
					}
				}
				euler(U);
				reverse(begin(EC), end(EC));
				for(int x : EC) cout << x << ' ';
			}
		}
