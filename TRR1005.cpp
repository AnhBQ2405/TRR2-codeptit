#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define pi 3.141592654
#define mod 1000000007
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int main(){
			fstream in, out;
			in.open("DT.INP", ios :: in);
			out.open("DT.OUT", ios :: out);
			int t, n, m; in >> t >> n >> m;
			vector<int> ke[1001];
			for(int i = 1; i <= m; i++){
			    int u, v; in >> u >> v;
			    ke[u].pb(v);
			    ke[v].pb(u);
			}
			if(t == 1){
				for(int i = 1; i <= n; i++) out << ke[i].size() << ' ';
			}
			else{
				out << n << endl;
				for(int i = 1; i <= n; i++){
					out << ke[i].size() << ' ';
					for(int x : ke[i]){
						out << x << ' ';
					}
					out << endl;
				}
			}
		}
