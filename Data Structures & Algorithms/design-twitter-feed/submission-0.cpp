class Twitter {
public:
    int timestamp;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;

    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;

        followMap[userId].insert(userId);

        priority_queue<vector<int>> maxHeap;

        for (int followee : followMap[userId]) {
            if (tweetMap.find(followee) == tweetMap.end()) {
                continue;
            }

            int idx = tweetMap[followee].size() - 1;
            auto tweet = tweetMap[followee][idx];

            maxHeap.push({tweet.first, tweet.second, followee, idx});
        }

        while (!maxHeap.empty() && feed.size() < 10) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];

            feed.push_back(tweetId);

            idx--;

            if (idx >= 0) {
                auto nextTweet = tweetMap[user][idx];

                maxHeap.push({nextTweet.first,
                               nextTweet.second,
                               user,
                               idx});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }
};