#include<bits/stdc++.h>
using namespace std;    

vector<int> solve1(vector<int> &nums1, vector<int> &nums2) {
        int n=nums1.size();
        int m=nums2.size();
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        vector<int> ans;
        for(auto &it:st1){
            if(st2.find(it)!=st2.end()){
                ans.push_back(it);
            }
        }
        return ans;
}
        
     
vector<int> solve1(vector<int> &nums1, vector<int> &nums2) {
     int n=nums1.size();
        int m=nums2.size();
        set<int> intersection;
        int i=0, j=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i<n && j<m) {
            if(nums1[i] < nums2[j]) {
                i++;
            } else if(nums1[i] > nums2[j]) {
                j++;
            } else {
                intersection.insert(nums1[i]);
                i++;
                j++;
            }
        }
        vector<int>ans;
        for(auto &num:intersection){
            ans.push_back(num);
        }
        return ans;
            }
int main(){
    int n,m;
    cout<<"Enter the size of the array1: ";
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the size of the array2: ";
    cin>>m;
    vector<int> arr2(n);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    cout<<"The intersection elements are: ";
    vector<int>ans=solve1(arr1,arr2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}