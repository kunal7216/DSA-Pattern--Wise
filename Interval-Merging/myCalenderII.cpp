// my calender 3 
// leetcode no 732

*********************************************************Brute Solution**********************************************************************************
  class MyCalendarThree {
public:
    vector<pair<int,int>> bookings;

    MyCalendarThree() {}

    int book(int start, int end) {
        bookings.push_back({start, end});

        int ans = 0;

        for (int t = 0; t <= 1000000; t++) {
            int cnt = 0;

            for (auto &b : bookings) {
                if (b.first <= t && t < b.second)
                    cnt++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
*********************************************************Better Solution**********************************************************************************
  class MyCalendarThree {
public:
    map<int,int> diff;

    MyCalendarThree() {}

    int book(int start, int end) {
        diff[start]++;
        diff[end]--;

        int active = 0;
        int ans = 0;

        for (auto &p : diff) {
            active += p.second;
            ans = max(ans, active);
        }

        return ans;
    }
};
*********************************************************Optimal Solution**********************************************************************************
  class Node {
public:
    int val = 0;
    int lazy = 0;

    Node* left = nullptr;
    Node* right = nullptr;
};

class MyCalendarThree {
private:
    Node* root;

    void update(Node* node,
                int start,
                int end,
                int l,
                int r) {

        if (r < start || end < l)
            return;

        if (l <= start && end <= r) {
            node->val++;
            node->lazy++;
            return;
        }

        int mid = start + (end - start) / 2;

        if (!node->left)
            node->left = new Node();

        if (!node->right)
            node->right = new Node();

        update(node->left, start, mid, l, r);
        update(node->right, mid + 1, end, l, r);

        node->val =
            node->lazy +
            max(node->left->val,
                node->right->val);
    }

public:
    MyCalendarThree() {
        root = new Node();
    }

    int book(int start, int end) {
        update(root,
               0,
               1000000000,
               start,
               end - 1);

        return root->val;
    }
};
