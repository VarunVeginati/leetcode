class FoodRatings {
public:
    map<string,set<pair<int,string> >> m;
    unordered_map<string,string> cuisine_map;
    unordered_map<string,int> rating_m;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<cuisines.size(); i++) {
            m[cuisines[i]].insert(make_pair(-1*ratings[i], foods[i]));
            cuisine_map[foods[i]] = cuisines[i];
            rating_m[foods[i]] = -1*ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = cuisine_map[food];
        m[cuisine].erase(make_pair(rating_m[food], food));
        rating_m[food] = -1*newRating;
        m[cuisine].insert(make_pair(-1*newRating, food));
    }
    
    string highestRated(string cuisine) {
        auto it = m[cuisine].begin();
        return (*it).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */