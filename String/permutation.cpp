#include<bits/stdc++.h>
using namespace std;        
void solve(vector<int>&nums, vector<vector<int>>&ans,int index){
        //base case
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=index;j<nums.size();j++){
            swap(nums[index], nums[j]);
            solve(nums, ans,index+1);
            swap(nums[index], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }

int main(){
    vector<int> s = {1, 2, 3};
    vector<vector<int>> permutations = permute(s);  
    cout << "Permutations are: " << endl;
    for (const auto& perm : permutations) {
        cout << "{ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}