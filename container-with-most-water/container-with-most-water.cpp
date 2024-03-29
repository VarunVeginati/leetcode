class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0;
        int p2 = height.size()-1;
        int max_area = 0;
        
        while(p1<p2) {
            max_area = max(max_area, min(height[p1], height[p2])*(p2-p1));
            if(height[p1]<height[p2]) p1++;
            else p2--;
        }
        
        return max_area;
    }
};