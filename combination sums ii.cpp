#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>& ar, int sum, vector<vector<int>>& res, vector<int>& r, int i){
    if(sum<0) return;
    if(sum==0){
        res.push_back(r);
        return;
    }

    while(i<ar.size() && sum>=ar[i]){
        r.push_back(ar[i]);
        dfs(ar, sum-ar[i], res, r, i+1);
        while(ar[i]==ar[i+1]) i++;
        i++;
        r.pop_back();

    }
    return;
}

vector<vector<int>> solution(vector<int>& ar, int sum){
    sort(ar.begin(), ar.end());

    vector<vector<int>> res;
    vector<int> r;
    dfs(ar, sum, res, r, 0);

    return res;
}

int main(){
    int  t;
    cin>>t;
    while(t--){
        int n, z;
        cin>>n;
        vector<int> a;
        for(int i=0; i<n; i++){
         cin>>z;
         a.push_back(z);
        }
        int sum;
        cin>>sum;
        vector<vector<int>> ans = solution(a, sum);
        if(ans.empty()) cout<<"Empty"<<endl;
        else{
            for(int i=0; i<ans.size(); i++){
                cout<<"(";
                 for(int j=0; j<ans[i].size(); j++){
                    if(j!=ans[i].size()-1)cout<<ans[i][j]<<" ";
                    else cout<<ans[i][j];
                 }
            cout<<")";
            }
        cout<<endl;
        }
    }
}
