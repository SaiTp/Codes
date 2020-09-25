#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> myVec, int index, int k){
   // base condition
    if(myVec.size()==1) return myVec[0];
    index = (index+k-1)%myVec.size();
    myVec.erase(myVec.begin()+index);
    return solve(myVec, index, k);
}
int josephus(int n, int k)
{
  vector<int> myVec;

  for(int i=1; i<=n; i++)
        myVec.push_back(i);

  return solve(myVec, 0, k);
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n, k;
    cin>>n>>k;
    cout<<josephus(n, k);}
}
