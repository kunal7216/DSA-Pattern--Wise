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
