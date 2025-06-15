#include<bits/stdc++.h>
using namespace std;
int solve(int arr[], int n, int k) {
    int left = 0, right = 0, sum = 0, maxLength = 0;

    while (right < n) {
        sum += arr[right];

        while (sum > k ) {
            sum -= arr[left];
            left++;
        }

        if (sum <= k) {
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
    }

    cout << "Length of the longest subarray with sum " << k << " is: " << maxLength << endl;
    return maxLength;

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    solve(arr.data(), n, k);
    return 0;
}