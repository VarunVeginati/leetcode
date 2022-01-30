class Vector2D {
public:
    vector<int> res;
    int k=0;
    
    Vector2D(vector<vector<int>>& vec) {
        for(int i=0; i<vec.size(); i++) {
            for(int j=0; j<vec[i].size(); j++) {
                res.push_back(vec[i][j]);
            }
        }
    }
    
    int next() {
        return res[k++];
    }
    
    bool hasNext() {
        return k<res.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */