class Twitter {
private:
    map<int, set<int> > followers;
    map<int, set<int> > following;
    map<int, vector<pair<int,int> >> tweets;
    map<int, priority_queue<vector<int>>> feed;
    int time;
    
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(tweetId, time));
        feed[userId].push({time, tweetId, userId});
        for(auto follower: followers[userId]) {
            feed[follower].push({time, tweetId, userId});
        }
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq = feed[userId];
        vector<int> res;
        set<int> followingUsers = following[userId];
        
        while(!pq.empty() && res.size()<10) {
            if(pq.top()[2]==userId || followingUsers.find(pq.top()[2]) != followingUsers.end())
                res.push_back(pq.top()[1]);
            pq.pop();
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId) != following[followerId].end()) return;
        followers[followeeId].insert(followerId);
        following[followerId].insert(followeeId);
        
        vector<pair<int,int> > followeeTweets = tweets[followeeId];
        
        for(pair<int,int> tweet: followeeTweets) {
            feed[followerId].push({tweet.second, tweet.first, followeeId});
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        followers[followeeId].erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */