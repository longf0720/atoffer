#define MAGIC 0x13572468
class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }

    int pop() {
        // write your code here
        int popValue = MAGIC;
        if (stack2.empty()) {
            while (stack1.size() > 1) {
                popValue = stack1.top();
                stack1.pop();
                stack2.push(popValue);
            }
            if (stack1.empty()) {
                perror("Queue is empty");
                return MAGIC;
            } else {
                popValue = stack1.top();
                stack1.pop();
                return popValue;
            }
        } else {
            popValue = stack2.top();
            stack2.pop();
            return popValue;
        }
    }

    int top() {
        // write your code here
        int popValue = MAGIC;
        if (stack2.empty()) {
            while (stack1.size() > 1) {
                popValue = stack1.top();
                stack1.pop();
                stack2.push(popValue);
            }
            if (stack1.empty()) {
                perror("Queue is empty");
                return MAGIC;
            } else {
                popValue = stack1.top();
                stack1.pop();
                stack2.push(popValue);
                return popValue;
            }
        } else {
            popValue = stack2.top();
            // stack2.pop();
            return popValue;
        }
    }
};
