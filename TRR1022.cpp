#include<bits/stdc++.h>
#define ll long long
#define pi 3.141592654
#define mod 1000000007
#define ii pair<int, int>
#define pb push_back
#define faster() ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std; 
		int a[1001][1001], b[1001][1001], V, E, U, visited[1001], cnt[1001], in[1001], out[1001]; vector<int> ke[1001], EC; 
		int main(){
			freopen("DT.INP", "r", stdin);
			freopen("DT.OUT", "w", stdout);
			memset(a, -1, sizeof(a));
			int t; cin >> t >> V >> E;
			memset(in, 0, sizeof(in));
			memset(out, 0, sizeof(out));
			for(int i = 1; i <= E; i++){
				int x, y, z; cin >> x >> y >> z;
				in[y]++; out[x]++;
				a[x][y] = z;
			}
			if(t == 1){
				for(int i = 1; i <= V; i++) cout << in[i] << ' ' << out[i] << endl;
			}
			else{
				cout << V << endl;
				for(int i = 1; i <= V; i++){
					for(int j = 1; j <= V; j++){
						if(i == j) cout << 0 << ' ';
						else if(a[i][j] == -1) cout << 10000 << ' ';
						else cout << a[i][j] << ' ';
					}
					cout << endl;
				}
			}
		}
