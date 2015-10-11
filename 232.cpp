// https://leetcode.com/problems/implement-queue-using-stacks/
class Queue {
 public:
  // Push element x to the back of queue.
  void push(int x) { stack_normal_.push(x); }

  // Removes the element from in front of queue.
  void pop(void) {
    if (!stack_reverse_.empty()) {
      stack_reverse_.pop();

      return;
    }
    inner_swap();
    stack_reverse_.pop();
  }

  // Get the front element.
  int peek(void) {
    if (!stack_reverse_.empty()) {
      return stack_reverse_.top();
    }
    inner_swap();
    return stack_reverse_.top();
  }

  // Return whether the queue is empty.
  bool empty(void) { return stack_reverse_.empty() && stack_normal_.empty(); }

 private:
  void inner_swap() {
    while (!stack_normal_.empty()) {
      stack_reverse_.push(stack_normal_.top());
      stack_normal_.pop();
    }
  }
  std::stack<int> stack_reverse_;
  std::stack<int> stack_normal_;
};
