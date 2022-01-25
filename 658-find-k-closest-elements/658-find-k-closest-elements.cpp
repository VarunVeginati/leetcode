class Solution {
public:
    
    int binary_search(vector<int>& arr, int l, int r, int x) {
        while(l<=r) {
            int mid = (l+r)/2;
            
            if(arr[mid]==x) return mid;
            if(mid==0) {
                if(abs(arr[0]-x) <= abs(arr[1]-x)) return 0;
                else return 1;
            } 
            if(mid==arr.size()-1) {
                if(abs(arr[arr.size()-2]-x) <= abs(arr[arr.size()-1]-x))
                    return arr.size()-2;
                else return arr.size()-1;
            } 
            if(x<arr[mid] && x>arr[mid-1]) {
                if(abs(arr[mid-1]-x) <= abs(arr[mid]-x))
                    return mid-1;
                else
                    return mid;
            }
            if(x>arr[mid] && x<arr[mid+1]) {
                if(abs(arr[mid]-x) <= abs(arr[mid+1]-x))
                    return mid;
                else
                    return mid+1;
            }
            if(x>arr[mid]) return binary_search(arr, mid+1, r, x);
            else return binary_search(arr, l, mid-1, x);
        }
        return -1;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int pos = 0;
        if(x<=arr[0] || n==1) pos = 0;
        else if(x>=arr[n-1]) pos=n-1;
        else {
            pos = binary_search(arr, 0, n-1, x);
        }
        
        vector<int> vec;
        vec.push_back(arr[pos]);
        k--;
        int l = pos-1;
        int r = pos+1;
        
        while(k>0) {
            if(l>=0 && r<=n-1) {
                if(abs(arr[l]-x) <= abs(arr[r]-x)) {
                    vec.push_back(arr[l]);
                    l--;
                    k--;
                } else {
                    vec.push_back(arr[r]);
                    r++;
                    k--;
                }
            } else if(l<0 && r>n-1) {
                break;
            } else if(l<0) {
                vec.push_back(arr[r]);
                r++;
                k--;
            } else if(r>n-1) {
                vec.push_back(arr[l]);
                l--;
                k--;
            }
        }
        
        sort(vec.begin(), vec.end());
        
        return vec;
    }
};