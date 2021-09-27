
#include<bits/stdc++.h>
using namespace std;
/* Head ends here */
multiset<int> max1, min1;
//print

void print(){
    float a, b;
    //bool f1, f2;
    if(max1.size()>min1.size()+1){
                min1.insert(*max1.rbegin());
                max1.erase(max1.find(*max1.rbegin()));
            }
    else if(min1.size()>max1.size()+1){
                max1.insert(*min1.begin());
                min1.erase(min1.begin());
    }
    if(max1.empty() && min1.empty()){
        cout<<"Wrong!"<<endl;
        return;
    }
    if(max1.size()==min1.size()){
        a = *max1.rbegin();
        b = *min1.begin();
            double p;
            p = (a + b)/2.0;
            string s = to_string(p);
            size_t found = s.find('.');
            if(s[found+1]=='5') s.erase(s.begin()+found+2, s.end());
            else s.erase(s.begin()+found,s.end());
            cout<<s<<endl;

    }
    else if(max1.size()>min1.size()) {
        cout<<*max1.rbegin()<<endl;
    }
    else if(max1.size()<min1.size()) {
        cout<<*min1.begin()<<endl;
    }
    return;
}
void median(vector<char> s,vector<int> a, int n) {
    for(int i=0; i<n; i++){
        if(s[i]=='a'){
            if(max1.empty() || *max1.rbegin()>a[i]){
                max1.insert(a[i]);
            }
            else min1.insert(a[i]);
            if(max1.size()>min1.size()+1){
                min1.insert(*max1.rbegin());
                max1.erase(max1.find(*max1.rbegin()));
            }
            else if(min1.size()>max1.size()+1){
                max1.insert(*min1.begin());
                min1.erase(min1.begin());
            }
            print();
        }
        else{
            multiset<int>:: iterator t1=max1.find(a[i]), t2=min1.find(a[i]);
            if(t1==max1.end() && t2==min1.end()){
                cout<<"Wrong!"<<endl;
            }
            else{
                if(t1!=max1.end()){
                    max1.erase(t1);
                }
                else{
                    min1.erase(t2);
                }
                print();
            }
        }
    }
}
int main(void){

//Helpers for input and output

	int N;
	cin >> N;

	vector<char> s;
    vector<int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}

	median(s,X,N);
	return 0;
}
