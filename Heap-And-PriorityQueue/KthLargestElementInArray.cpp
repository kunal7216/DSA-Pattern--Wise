// kth largest element in an array
// leetcode problem link: https://leetcode.com/problems/kth-largest-element-in-an-array/\


// using min heap

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        // Min-heap to store the k largest elements seen so far
        priority_queue<int, vector<int>, greater<int>> minpq;

        // Traverse all elements in the array
        for (int i = 0; i < nums.size(); i++)
        {

            // If heap size is less than k, push the element
            if (minpq.size() < k)
            {
                minpq.push(nums[i]);
            }
            else
            {
                // If current element is larger than the smallest
                // element in the heap, replace it
                if (minpq.top() < nums[i])
                {
                    minpq.pop();
                    minpq.push(nums[i]);
                }
            }
        }

        // The top of the min-heap is the kth largest element
        return minpq.top();
    }
};

*********************************************************Brute Selection***********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k - 1];
    }
};
*********************************************************Better Selection***********************************************************************************
    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
*********************************************************Optimal Solution***********************************************************************************


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int target = k - 1; // index in descending order

        srand(time(0));

        while (left <= right) {
            int pivotIndex = left + rand() % (right - left + 1);
            int pivot = nums[pivotIndex];

            int lt = left;
            int i = left;
            int gt = right;

            // Partition in descending order:
            // nums[left...lt-1] > pivot
            // nums[lt...gt] == pivot
            // nums[gt+1...right] < pivot
            while (i <= gt) {
                if (nums[i] > pivot) {
                    swap(nums[i], nums[lt]);
                    i++;
                    lt++;
                }
                else if (nums[i] < pivot) {
                    swap(nums[i], nums[gt]);
                    gt--;
                }
                else {
                    i++;
                }
            }

            if (target >= lt && target <= gt) {
                return nums[target];
            }
            else if (target < lt) {
                right = lt - 1;
            }
            else {
                left = gt + 1;
            }
        }

        return -1;
    }
};
