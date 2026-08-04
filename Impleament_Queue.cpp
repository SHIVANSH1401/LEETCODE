/*Two stacks are used to simulate queue behavior. New elements are pushed into the input stack, and when a front element is needed, all elements are transferred to the output stack if it's empty. This reversal preserves FIFO order, giving amortized O(1) time for queue operations.*/

class MyQueue {
public:
    stack<int> in, out;

    MyQueue() {
    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        peek();
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};