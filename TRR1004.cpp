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
			int t, V, E; in >> t >> V >> E;
			int a[V + 1][V + 1], cnt[1001], ans = 0; vector<int> ke[1001];
			memset(a, 0, sizeof(a));
			for(int i = 1; i <= E; i++){
				int u, v; in >> u >> v;
				a[u][v] = a[v][u] = 1;
				cnt[u]++; cnt[v]++;
			}
			if(t == 1){
				for(int i = 1; i <= V; i++) out << cnt[i] << ' ';
			}
			else{
			    out << V << endl;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++) out << a[i][j] << ' ';
					out << endl;
				}
			}
			in.close();
			out.close();
		}
