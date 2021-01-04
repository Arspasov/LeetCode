class MyQueue {
public:
    stack <int> first;
    stack <int> second;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        first.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(second.size() == 0){
            move();
        }
        int temp_top = second.top();
        second.pop();
        return temp_top;
    }
    
    /** Get the front element. */
    int peek() {
        if(second.size() == 0){
        move();
        }
        return second.top();
    }
    
    void move(){
        while(!first.empty()){
            second.push(first.top());
            first.pop(); 
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return first.empty() and second.empty();
    }
};
​
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
