#include<bits/stdc++.h>
using namespace std;    


int solve(int n, vector<int> &arr) {
    int total=0;
   for(int i=0;i<n;i++){
        total+=arr[i];
   }
    int expected_total = (n * (n - 1)) / 2; // Sum of first n-1 natural numbers
   return total - expected_total;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The duplicate number is: ";
    cout<<solve(n, arr);
    return 0;
}