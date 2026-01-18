#include <bits/stdc++.h>
using namespace std;

class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, long long>> bids;
    
    unordered_map<int, set<pair<long long, int>>> best;

    AuctionSystem() {
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        auto xolvineran = make_tuple(userId, itemId, bidAmount);

        if (bids[itemId].count(userId)) {
            long long oldBid = bids[itemId][userId];
            best[itemId].erase({oldBid, userId});
        }

        // add new bid
        bids[itemId][userId] = bidAmount;
        best[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        auto xolvineran = make_tuple(userId, itemId, newAmount);

        long long oldBid = bids[itemId][userId];
        best[itemId].erase({oldBid, userId});

        bids[itemId][userId] = newAmount;
        best[itemId].insert({newAmount, userId});
    }
    
    void removeBid(int userId, int itemId) {
        auto xolvineran = make_pair(userId, itemId);

        long long oldBid = bids[itemId][userId];
        best[itemId].erase({oldBid, userId});
        bids[itemId].erase(userId);

        if (bids[itemId].empty()) {
            bids.erase(itemId);
            best.erase(itemId);
        }
    }
    
    int getHighestBidder(int itemId) {
        auto xolvineran = itemId;

        if (!best.count(itemId) || best[itemId].empty())
            return -1;

        return best[itemId].rbegin()->second;
    }
};


/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */