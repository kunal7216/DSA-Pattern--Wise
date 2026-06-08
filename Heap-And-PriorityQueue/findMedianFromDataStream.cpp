// find median from data stream
// leetcode 295: https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder
{
public:
    // Max-heap to store the smaller half of the numbers
    priority_queue<int> lowerHalf;

    // Min-heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> upperHalf;

    // Constructor
    MedianFinder() {}

    // Adds a number into the data structure
    void addNum(int num)
    {

        // Step 1: Insert number into the appropriate heap
        if (lowerHalf.empty() || num <= lowerHalf.top())
        {
            // If number is smaller, it belongs to lowerHalf
            lowerHalf.push(num);
        }
        else
        {
            // Otherwise, it belongs to upperHalf
            upperHalf.push(num);
        }

        // Step 2: Balance the heaps so that:
        // - lowerHalf has either equal elements or one extra element
        if (lowerHalf.size() > upperHalf.size() + 1)
        {
            // Move the maximum element from lowerHalf to upperHalf
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        }
        else if (upperHalf.size() > lowerHalf.size())
        {
            // Move the minimum element from upperHalf to lowerHalf
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }

    // Returns the median of all inserted numbers
    double findMedian()
    {

        // If odd number of elements,
        // median is the top of lowerHalf
        if (lowerHalf.size() > upperHalf.size())
        {
            return lowerHalf.top();
        }
        // If even number of elements,
        // median is the average of two middle elements
        else
        {
            return (lowerHalf.top() + upperHalf.top()) / 2.0;
        }
    }
};

*****************************************************************Brute Solution********************************************************************************
    class MedianFinder {
private:
    vector<int> nums;

public:
    MedianFinder() {
        
    }

    void addNum(int num) {
        nums.push_back(num);
    }

    double findMedian() {
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        int n = temp.size();

        if (n % 2 == 1) {
            return temp[n / 2];
        } else {
            int mid1 = temp[n / 2 - 1];
            int mid2 = temp[n / 2];

            return (mid1 + mid2) / 2.0;
        }
    }
};
*****************************************************************Better Solution********************************************************************************
    class MedianFinder {
private:
    vector<int> nums;

public:
    MedianFinder() {
        
    }

    void addNum(int num) {
        auto position = lower_bound(nums.begin(), nums.end(), num);

        nums.insert(position, num);
    }

    double findMedian() {
        int n = nums.size();

        if (n % 2 == 1) {
            return nums[n / 2];
        } else {
            int mid1 = nums[n / 2 - 1];
            int mid2 = nums[n / 2];

            return (mid1 + mid2) / 2.0;
        }
    }
};
*****************************************************************Optimal Solution********************************************************************************
class MedianFinder {
private:
    priority_queue<int> leftMaxHeap;

    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

public:
    MedianFinder() {
        
    }

    void addNum(int num) {
        if (leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        } else {
            rightMinHeap.push(num);
        }

        if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } 
        else if (rightMinHeap.size() > leftMaxHeap.size() + 1) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    double findMedian() {
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        } 
        else if (rightMinHeap.size() > leftMaxHeap.size()) {
            return rightMinHeap.top();
        } 
        else {
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        }
    }
};
