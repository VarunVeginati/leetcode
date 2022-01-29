class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int> > st;
        
        st.push(make_pair(-1, 0));
        st.push(make_pair(0, heights[0]));
        
        int max_area = 0;
        
        for(int i=1; i<heights.size(); i++) {
            while(heights[i]<=st.top().second && st.top().first != -1) {
                pair<int,int> pr = st.top();
                st.pop();
                max_area = max(max_area, pr.second*(i-st.top().first-1));
            }
            st.push(make_pair(i, heights[i]));
        }
        
        while(st.top().first != -1) {
            pair<int,int> p = st.top();
            st.pop();
            int a = p.second*(heights.size()-st.top().first-1);
            max_area = max(max_area, a);
        }
        
        return max_area;
    }
};