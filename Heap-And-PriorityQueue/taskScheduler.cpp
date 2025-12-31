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
