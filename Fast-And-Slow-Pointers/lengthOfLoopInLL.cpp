******************************************************************Brute Solution*************************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    int countNodesinLoop(Node *head) {
        Node* start = head;

        // Treat every node as a possible loop starting point
        while (start != NULL) {
            Node* temp = start->next;
            int count = 1;

            // Move forward and check if we reach start again
            while (temp != NULL) {
                if (temp == start) {
                    return count;
                }

                temp = temp->next;
                count++;
            }

            start = start->next;
        }

        return 0;
    }
};
******************************************************************Better Solution*************************************************************************************
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    int countNodesinLoop(Node *head) {
        unordered_map<Node*, int> visited;

        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            // If node is already visited, loop is found
            if (visited.find(temp) != visited.end()) {
                return position - visited[temp];
            }

            // Store current node with its position
            visited[temp] = position;

            temp = temp->next;
            position++;
        }

        // No loop found
        return 0;
    }
};
******************************************************************Optimal Solution*************************************************************************************

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
