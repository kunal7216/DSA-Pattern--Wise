******************************************************************Brute solution*********************************************************************************
  class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        // Try every person as possible judge
        for (int candidate = 1; candidate <= n; candidate++) {
            
            bool candidateTrustsSomeone = false;
            int peopleTrustingCandidate = 0;
            
            // Check all trust relationships
            for (int i = 0; i < trust.size(); i++) {
                int a = trust[i][0];
                int b = trust[i][1];
                
                // If candidate trusts someone, candidate cannot be judge
                if (a == candidate) {
                    candidateTrustsSomeone = true;
                    break;
                }
                
                // If someone trusts candidate, count it
                if (b == candidate) {
                    peopleTrustingCandidate++;
                }
            }
            
            // Judge trusts nobody and is trusted by n - 1 people
            if (!candidateTrustsSomeone && peopleTrustingCandidate == n - 1) {
                return candidate;
            }
        }
        
        return -1;
    }
};
******************************************************************Better solution*********************************************************************************
  class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        
        // Build indegree and outdegree arrays
        for (int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            
            // a trusts b
            outdegree[a]++;
            indegree[b]++;
        }
        
        // Find the person who is trusted by n - 1 people
        // and trusts nobody
        for (int person = 1; person <= n; person++) {
            if (indegree[person] == n - 1 && outdegree[person] == 0) {
                return person;
            }
        }
        
        return -1;
    }
};
******************************************************************Optimal Solution*********************************************************************************
  class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> score(n + 1, 0);
        
        // Process every trust relationship
        for (int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            
            // a trusts someone, so a cannot be judge
            score[a]--;
            
            // b is trusted by someone, so b gets one point
            score[b]++;
        }
        
        // Judge should have score n - 1
        for (int person = 1; person <= n; person++) {
            if (score[person] == n - 1) {
                return person;
            }
        }
        
        return -1;
    }
};
