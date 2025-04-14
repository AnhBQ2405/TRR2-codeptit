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
				int t, n; in >> t >> n;
				vector<ii> canh;
				vector<int> cnt(n + 1, 0);
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++){
						int x; in >> x;
						cnt[i] += x;
						if(x && i < j) canh.pb({i, j});
					}
				}
				if(t == 1){
					for(int i = 1; i <= n; i++) out << cnt[i] << ' ';
				}
				else{
					int p = canh.size();
					out << n << ' ' << p << endl;
					vector<vector<int>> a(n + 1, vector<int>(p + 1));
					for(int j = 0; j < p; j++){
						a[canh[j].first][j + 1] = 1;
						a[canh[j].second][j + 1] = 1;
					}
					for(int i = 1; i <= n; i++){
						for(int j = 1; j <= p; j++) out << a[i][j] << ' ';
						out << endl;
					}
				}
			}
