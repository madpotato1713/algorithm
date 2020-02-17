/* CASE1 */
class MinStack {
private:
	vector<int> minStack;
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		minStack.push_back(x);
	}

	void pop() {
		minStack.erase(minStack.end() - 1);
	}

	int top() {
		return minStack[minStack.size() - 1];
	}

	int getMin() {
		return *min_element(minStack.begin(), minStack.end());
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


/* CASE2 */
class MinStack {
private:
	stack<int> st;
	stack<int> minSt;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		st.push(x);
		minSt.push(minSt.empty() ? x : min(minSt.top(), x));
	}

	void pop() {
		st.pop();
		minSt.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return minSt.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

