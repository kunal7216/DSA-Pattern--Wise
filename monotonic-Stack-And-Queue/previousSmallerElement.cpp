vector<int> previousSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> s; // Stack to keep track of previous smaller elements

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack until we find a smaller element or the stack is empty
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If the stack is empty, there is no smaller element to the left
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top(); // The top element is the previous smaller element
        }

        // Push the current element onto the stack
        s.push(arr[i]);
    }

    return result;
}