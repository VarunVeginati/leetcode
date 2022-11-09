class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()) {
            st.push(make_pair(price,1));
            return 1;
        }
        
        int cnt = 1;
        
        while(!st.empty() && st.top().first<=price) {
            cnt = cnt+st.top().second;
            st.pop();
        }
        
        st.push(make_pair(price, cnt));
        
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */