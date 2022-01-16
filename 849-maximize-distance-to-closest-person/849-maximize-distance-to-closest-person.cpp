class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> occupied_seats;
        
        for(int i=0; i<seats.size(); i++)
            if(seats[i]==1) occupied_seats.push_back(i);
        
        int mx=occupied_seats[0];
        int n = occupied_seats.size();
        
        for(int i=1; i<occupied_seats.size(); i++) {
            mx = max(mx,(occupied_seats[i]-occupied_seats[i-1])/2);
        }
        
        int a = (seats.size()-1-occupied_seats[n-1]);
        
        mx = max(mx, a);
        
        return mx;
    }
};