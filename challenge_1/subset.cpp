// Given an integer array nums of unique elements, return all possible 
// subsets. The solution set must not contain duplicate subsets. Return the solution in any order.


// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        generate(0,nums,curr,res);
        return res;
    }

    void generate(int index,vector<int> &nums,vector<int> &curr, vector<vector<int>> &res){
        res.push_back(curr);

        for(int i =index;i<nums.size();i++){
            curr.push_back(nums[i]);
            generate(i+1,nums,curr,res);
            curr.pop_back();
        }
    }