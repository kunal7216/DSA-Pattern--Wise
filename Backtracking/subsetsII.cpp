// Subset  II --90
// link : https://leetcode.com/problems/subsets-ii/description/


                                                                                      // Brute 
class Solution {
public:
    set<vector<int>> st;

    void solve(int index, vector<int>& nums, vector<int>& temp) {
        if (index == nums.size()) {
            vector<int> curr = temp;
            sort(curr.begin(), curr.end());
            st.insert(curr);
            return;
        }

        // Take
        temp.push_back(nums[index]);
        solve(index + 1, nums, temp);
        temp.pop_back();

        // Not Take
        solve(index + 1, nums, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;

        solve(0, nums, temp);

        return vector<vector<int>>(st.begin(), st.end());
    }
};


                                                                                  // Better Solution 
class Solution {
public:
    set<vector<int>> st;

    void solve(int index, vector<int>& nums, vector<int>& temp) {

        if (index == nums.size()) {
            st.insert(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(index + 1, nums, temp);
        temp.pop_back();

        solve(index + 1, nums, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> temp;

        solve(0, nums, temp);

        return vector<vector<int>>(st.begin(), st.end());
    }
};




                                                                         // Optimal (Backtracking + Skip Duplicates)
class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int start, vector<int>& nums, vector<int>& temp) {

        // Every state is a valid subset
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);

            backtrack(i + 1, nums, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> temp;

        backtrack(0, nums, temp);

        return ans;
    }
};
