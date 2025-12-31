class Solution
{
public:
    int countNodesinLoop(ListNode *head)
    {

        // Step 1: Initialize slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 2: Detect cycle using Floyd's algorithm
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // Move slow by 1
            fast = fast->next->next; // Move fast by 2

            // Cycle detected
            if (slow == fast)
            {
                return countLoopLength(slow);
            }
        }

        // No cycle found
        return 0;
    }

private:
    int countLoopLength(ListNode *meet)
    {

        // Start counting from the meeting point
        int count = 1;
        ListNode *temp = meet->next;

        // Traverse the loop until we reach the same node again
        while (temp != meet)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};
// Using Floyd's Tortoise and Hare algorithm to find the length of the loop in a linked list