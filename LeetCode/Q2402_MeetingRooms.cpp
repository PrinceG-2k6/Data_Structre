#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Request {
        int start, end, id;
    };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int> result(m);
        vector<int> cnt(n, 0);
        vector<Request> reqs;

        // Create request list
        for (int i = 0; i < m; ++i) {
            reqs.push_back({meetings[i][0], meetings[i][1], i});
        }

        // Sort by start time
        sort(reqs.begin(), reqs.end(), [](const Request& a, const Request& b) {
            return a.start < b.start;
        });

        // Min-heap of available room IDs
        priority_queue<int, vector<int>, greater<>> avail;

        // Min-heap of (endTime, roomID)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> assign;

        for (int i = 0; i < n; ++i) avail.push(i);

        for (auto& request : reqs) {
            long long start = request.start, end = request.end;

            // Free up rooms that have completed their meetings
            while (!assign.empty() && start >= assign.top().first) {
                avail.push(assign.top().second);
                assign.pop();
            }

            if (!avail.empty()) {
                // Assign a free room
                int roomid = avail.top();
                avail.pop();
                cnt[roomid]++;
                result[request.id] = roomid;
                assign.push({end, roomid});
            } else {
                // Extend the meeting in the earliest available room
                auto [freeTime, room] = assign.top();
                assign.pop();
                assign.push({freeTime + (end - start), room});
                cnt[room]++;
                result[request.id] = room;
            }
        }

        // Find room with maximum meetings
        int maxi = -1;
        int index = -1;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > maxi) {
                index = i;
                maxi = cnt[i];
            }
        }

        return index;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> meetings ={{0,10},{1,5},{2,7},{3,4}};
    cout << sol.mostBooked(2,meetings) << endl;
}
    