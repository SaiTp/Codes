#include<bits/stdc++.h>
using namespace std;

int possibleWays(int n, int m, vector<vector<int>>& a){
    if(a[n][m]!=0) return a[n][m];
    if(m==0 && n==0) return 0;
    if(m==0 || n==0) return 1;

   a[n][m] = possibleWays(n-1, m, a) + possibleWays(n, m-1, a);
    return a[n][m];

}
int main(){
   int t;
   cin>>t;
   while(t--){
        int n, m, k;
        cin>>n>>m;
        vector<vector<int>> a;
        for(int i=0; i<n; i++){
            vector<int> r;
            for(int j=0; j<m; j++){
                r.push_back(0);
            }
            a.push_back(r);
        }
        cout<<possibleWays(n-1, m-1, a)<<endl;
    }
    return 0;
}
