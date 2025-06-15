#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=nums[0];
        int curr_sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]+curr_sum>nums[i]){
                curr_sum=nums[i]+curr_sum;
            }else{
                curr_sum=nums[i];
            }
            if(curr_sum>max_sum){
                max_sum=curr_sum;
            }
        }
        return max_sum;
    }

    int main(){
        int n;
        cout<<"Enter the size of the array: ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of the array: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"The maximum subarray sum is: ";
        cout<<maxSubArray(arr);
        return 0;
    }