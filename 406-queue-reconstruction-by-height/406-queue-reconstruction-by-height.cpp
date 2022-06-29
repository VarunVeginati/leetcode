class LinkedList{
private:
	struct Node{
		int h;
        int k;
		Node* next = NULL;

		Node() {}
		Node(int h, int k): h(h),k(k) {}
	} *Head;

public:
	LinkedList() {
		Head = new Node();
	}

	void addNodeAtEnd(int h, int k) {
		Node* curr = Head;
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new Node(h,k);
	}

	void addNodeAtBegining(int h, int k) {
		Node * curr = Head;
		Node * currNext = curr->next;
		curr->next = new Node(h,k);
		curr->next->next = currNext;
	}

	void addNodeInBetween(int h, int k, int index) {
		Node* curr = Head;

		while(index > 0) {
			curr = curr->next;
			index--;
		}

		Node* currNext = curr->next;
		curr->next = new Node(h,k);
		curr->next->next = currNext;
	}
    
    vector<vector<int>> getFinalList() {
        Node* curr = Head;
        curr = curr->next;
        vector<vector<int>> vec;
        
        while(curr != NULL) {
            vec.push_back({curr->h, curr->k});
            curr = curr->next;
        }
        
        return vec;
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if(a[0]==b[0]) return a[1]<b[1];
            else return a[0]>b[0];
        });
        
        LinkedList linkedList = LinkedList();
        
        for(int i=0; i<people.size(); i++) {
            linkedList.addNodeInBetween(people[i][0],people[i][1],people[i][1]);
        }
        
        return linkedList.getFinalList();
    }
};