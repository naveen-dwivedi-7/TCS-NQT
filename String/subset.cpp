
    #include<bits/stdc++.h>
using namespace std;
    
    void power(vector<int> nums, int i,vector<vector<int>>& result,vector<int> ans){
        //base case 
        if (i>=nums.size()){
            result.push_back(ans);
            return ;
        }

        //not pick 
        power(nums,i+1,result,ans);

        //pick
        ans.push_back(nums[i]);
        power(nums,i+1,result, ans);
         
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        
        power(nums,0,result, ans );
        return result;
    }

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    cout << "Subsets are: " << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}