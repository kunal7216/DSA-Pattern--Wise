// counting bits
//leetcode 338

************************************************************Brute Solution******************************************************************************************
    class Solution {
public:

    int countOnes(int num) {

        int count = 0;

        while(num) {
            num = num & (num - 1);
            count++;
        }

        return count;
    }

    vector<int> countBits(int n) {

        vector<int> ans;

        for(int i = 0; i <= n; i++) {
            ans.push_back(countOnes(i));
        }

        return ans;
    }
};
************************************************************Better Solution******************************************************************************************
    class Solution {
public:

    int countOnes(int num) {

        int count = 0;

        while(num) {
            num = num & (num - 1);
            count++;
        }

        return count;
    }

    vector<int> countBits(int n) {

        vector<int> ans;

        for(int i = 0; i <= n; i++) {
            ans.push_back(countOnes(i));
        }

        return ans;
    }
};
************************************************************Optimal Solution******************************************************************************************
class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> ans(n + 1, 0);

        // Start from 1 because ans[0] = 0
        for(int i = 1; i <= n; i++) {

            // DP relation
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};
