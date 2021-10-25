class MaxStack {
public:
    int max = INT_MIN;
    vector<pair<int, int> > vec;
    
    MaxStack() {
        
    }
    
    void push(int x) {
        if(x>max)
            max = x;
        vec.push_back(make_pair(x, max));
    }
    
    int pop() {
        int pop_element = vec[vec.size()-1].first;
        vec.pop_back();
        if(vec.size() == 0)
            max = INT_MIN;
        else
            max = vec[vec.size()-1].second;
        return pop_element;
    }
    
    int top() {
        return vec[vec.size()-1].first;
    }
    
    int peekMax() {
        return vec[vec.size()-1].second;
    }
    
    int popMax() {
        int max_element = vec[vec.size()-1].second;
        vector<pair<int,int> > dummy;
        int j = vec.size()-1;
        while(1) {
            if(vec[j].first != max_element) {
                dummy.push_back(vec[j]);
                vec.pop_back();
                j--;
            }
            else {
                vec.pop_back();
                break;
            }
        }
        
        if(vec.size() == 0)
            max = INT_MIN;
        else
            max = vec[vec.size()-1].second;
        
        for(int i=dummy.size()-1; i>=0; i--) {
            if(dummy[i].first > max) {
                max = dummy[i].first;
            }
            vec.push_back(make_pair(dummy[i].first, max));
        }
        
        return max_element;
    }
};