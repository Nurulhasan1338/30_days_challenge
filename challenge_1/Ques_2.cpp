// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations.
// The list must not contain the same combination twice, and the combinations may be returned in any order.

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
 
 
 vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> res;
        vector<int> curr;
        
        int target = n; 
        generate(1,9,curr,res,k,target);
        return res;
    }

    void generate(int start,int end,vector<int> &curr,vector<vector<int>> &res,int k,int tar){
        if(tar==0 && curr.size()==k){
            res.push_back(curr);
            return;
        }
        for(int i=start;i<=end;i++){
            curr.push_back(i);
            generate(i+1,9,curr,res,k,tar-i);
            curr.pop_back();
        }
    }