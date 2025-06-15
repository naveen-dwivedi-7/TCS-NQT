#include<bits/stdc++.h>
using namespace std;


int lis(vector<int> &a){
    int n=a.size();
   vector<int>output(n);
   output[0]=1;
   for(int i=1;i<n;i++){
    output[i]=1;
    for(int j=i-1;j>=0;j--){
        if(a[i]<a[j]){
            continue;
        }
        int possible_ans=output[j]+1;
        if(possible_ans>output[i]){
            output[i]=possible_ans;
        }   
    }
  }
    int ans=0;
    for(int i=0;i<n;i++){
     if(output[i]>ans){
          ans=output[i];
     }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans=lis(a);
    cout << ans << endl;
    
    return 0;
}