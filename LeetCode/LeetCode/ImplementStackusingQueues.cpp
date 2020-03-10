class MyStack {
	priority_queue<pair<int, int>> pq;
	int index;

public:
	/** Initialize your data structure here. */
	MyStack() {
		index = 0;
	}

	/** Push element x onto stack. */
	void push(int x) {
		pq.push(make_pair(index, x));
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int top = pq.top().second;
		pq.pop();
		return top;
	}

	/** Get the top element. */
	int top() {
		return pq.top().second;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return pq.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */