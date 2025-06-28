class Twitter {
public:
    vector<vector<int>> userTweet;
    vector<vector<int>> userFollower;
    Twitter() {
        userTweet.clear();
        userFollower.clear();
         
    }
    
    void postTweet(int userId, int tweetId) {
          userTweet.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int i=10;
        vector<int> temp;
        vector<int> vis(userTweet.size(),0);
           for(int j=userTweet.size()-1; j>=0; j--) {
             if((userTweet[j][0]==userId) && (vis[j]==0)) {
                            i--;
                           vis[j]=1;
                            temp.push_back(userTweet[j][1]);
                            if(i==0) break;
                            continue;
                    }
                for(int k=0; k<userFollower.size(); k++) {
                    if(userFollower[k][0]==userId && (vis[j]==0)) {
                           if(userTweet[j][0]==userFollower[k][1]) {
                            temp.push_back(userTweet[j][1]);
                           vis[j]=1;
                            i--;
                           }
                           if(i==0) break;
                    }
                    if(i==0) break;
                
                    
                } if(i==0) break;
           }

         return temp;
        }
    
    
    void follow(int followerId, int followeeId) {
        userFollower.push_back({followerId,followeeId});
        
    }
    
    void unfollow(int followerId, int followeeId) {
        for(int i=0; i<userFollower.size(); i++) {
            auto it=userFollower[i];
            if(it[0] == followerId && it[1]==followeeId) {
                   userFollower.erase(userFollower.begin() + i);
            }

        }
        
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