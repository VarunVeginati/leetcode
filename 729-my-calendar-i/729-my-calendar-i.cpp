class MyCalendar {
private:
    struct Node{
        int start;
        int end;
        
        Node* next = NULL;
        
        Node() {}
        Node(int h, int k): start(h),end(k) {}
    } *Head;
    
public:
    MyCalendar() {
        Head = new Node();
    }
    
    bool book(int start, int end) {
        Node* curr = Head;
        
        if(curr->next==NULL) {
            curr->next = new Node(start, end);
            return true;
        }
        
        if(curr->next->start>=end) {
            Node* currNext = curr->next;
            curr->next = new Node(start, end);
            curr->next->next = currNext;
            
            return true;
        }
        
        curr = curr->next;
        
        while(curr!=NULL && curr->next!=NULL && start>=curr->next->end) {
            curr = curr->next;
        }
        
        if(start<curr->end) return false;
        
        if(curr->next!=NULL && end>curr->next->start) return false;
        
        Node* currNext = curr->next;
        curr->next = new Node(start, end);
        curr->next->next = currNext;
        
//         if(start==20) {
//             Node* abc = Head;
//             abc = abc->next;
            
//             while(abc!=NULL) {
//                 cout << abc->start << "-" << abc->end <<endl;
//                 abc = abc->next;
//             }
//         }
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */