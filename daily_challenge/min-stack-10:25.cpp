class MinStack {
public:
    long min = INT_MAX;
    vector<pair<long,long> > vec;
    
    MinStack() {
    }
    
    void push(long val) {
        if(val < min)
            min = val;
        vec.push_back(make_pair(val,min));
    }
    
    void pop() {
        vec.pop_back();
        if(vec.size() == 0)
            min = INT_MAX;
        else
            min = vec[vec.size()-1].second;
    }
    
    int top() {
        return vec[vec.size()-1].first;
    }
    
    int getMin() {
        return vec[vec.size()-1].second;
    }
};