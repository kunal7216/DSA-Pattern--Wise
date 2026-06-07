// Task scheduler using a priority queue (min-heap) to manage tasks based on 
// their priority and execution time.

// leedcode.com/problems/task-scheduler/

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        // Frequency array to count occurrences of each task (A–Z)
        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char task : tasks)
        {
            freq[task - 'A']++;
        }

        // Sort frequencies in descending order
        // The most frequent task will be at freq[0]
        sort(freq.begin(), freq.end(), greater<int>());

        // Calculate initial idle slots
        // If the most frequent task appears freq[0] times,
        // we need (freq[0] - 1) gaps, each of size 'n'
        int idle = (freq[0] - 1) * n;

        // Fill idle slots using remaining tasks
        for (int i = 1; i < 26; i++)
        {
            // Each task can fill at most (freq[0] - 1) gaps
            idle -= min(freq[i], freq[0] - 1);
        }

        // If idle slots become negative, we don't need extra idle time
        idle = max(0, idle);

        // Total time = number of tasks + remaining idle slots
        return tasks.size() + idle;
    }
};


******************************************************************Brute Solution*************************************************************************


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        vector<int> lastTime(26, -1e9);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int totalTasks = tasks.size();
        int completed = 0;
        int time = 0;

        while (completed < totalTasks) {
            int bestTask = -1;
            int maxFreq = 0;

            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0 && time - lastTime[i] > n) {
                    if (freq[i] > maxFreq) {
                        maxFreq = freq[i];
                        bestTask = i;
                    }
                }
            }

            if (bestTask != -1) {
                freq[bestTask]--;
                lastTime[bestTask] = time;
                completed++;
            }

            time++;
        }

        return time;
    }
};
******************************************************************Better Solution*************************************************************************


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;

        for (int count : freq) {
            maxFreq = max(maxFreq, count);
        }

        int maxFreqTaskCount = 0;

        for (int count : freq) {
            if (count == maxFreq) {
                maxFreqTaskCount++;
            }
        }

        int formulaAnswer = (maxFreq - 1) * (n + 1) + maxFreqTaskCount;

        return max((int)tasks.size(), formulaAnswer);
    }
};
******************************************************************Optimal Solution*************************************************************************


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;

        for (int count : freq) {
            maxFreq = max(maxFreq, count);
        }

        int maxFreqTaskCount = 0;

        for (int count : freq) {
            if (count == maxFreq) {
                maxFreqTaskCount++;
            }
        }

        int formulaAnswer = (maxFreq - 1) * (n + 1) + maxFreqTaskCount;

        return max((int)tasks.size(), formulaAnswer);
    }
};
