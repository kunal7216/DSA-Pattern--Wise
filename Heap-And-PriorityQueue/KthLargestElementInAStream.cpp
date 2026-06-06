// kth Largest Element in a Stream
// LeetCode Problem Link: https://leetcode.com/problems/kth-largest-element-in-a-stream


class KthLargest
{
public:
    // Variable to store the value of k
    int k;

    // Min-Heap to store only the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Constructor initializes k and processes initial numbers
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;

        // Add all initial numbers using add()
        // This ensures heap size never exceeds k
        for (int num : nums)
        {
            add(num);
        }
    }

    // Adds a new value to the stream
    int add(int val)
    {

        // Insert the new value into the heap
        minHeap.push(val);

        // If heap size exceeds k, remove the smallest element
        // This keeps only the k largest elements in the heap
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }

        // The top of the min-heap is the kth largest element
        return minHeap.top();
    }
};


***************************************************************Brute Solution*****************************************************************************

class KthLargest {
private:
    int k;
    vector<int> stream;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        stream = nums;
    }

    int add(int val) {
        stream.push_back(val);

        sort(stream.begin(), stream.end());

        int n = stream.size();

        return stream[n - k];
    }
};
***************************************************************Better Solution*****************************************************************************


class KthLargest {
private:
    int k;
    vector<int> stream;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        stream = nums;

        sort(stream.begin(), stream.end());
    }

    int add(int val) {
        auto pos = lower_bound(stream.begin(), stream.end(), val);

        stream.insert(pos, val);

        int n = stream.size();

        return stream[n - k];
    }
};
***************************************************************Optimal SOlution*****************************************************************************


class KthLargest {
private:
    int k;

    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
