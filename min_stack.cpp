/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time. (easy difficulty)
(Does not do it in constant time for min)
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/



class MinStack {
private: 
    struct stackNode{
        int data;
        stackNode *next;
    };
    stackNode *head;
public:
    /** initialize your data structure here. */
    MinStack() {
        head = nullptr;
          
    }
    
    void push(int x) {
        
        stackNode *ptr = new stackNode;
        ptr->data = x;
        ptr->next = nullptr;
        if(!head)
            head = ptr;
        
        
        else{
            stackNode *cursor = ptr;
            cursor->next = head;
            head = cursor;         
        }  
    }
    
    void pop() {
        if(!head)
            return;
        
        stackNode *cursor = head;
        head = cursor->next;
        delete cursor;
    }
    
    int top() {    
        if(!head)
            return -1;
        
        return head->data;       
    }
    
    int getMin() {
        if(!head)
            return -1;
        
        stackNode *cursor = head;
        int min = cursor->data;
        while(cursor){
            if(cursor->data <= min)
                min = cursor->data;
            cursor = cursor->next;
        } 
        return min;       
    }
};
