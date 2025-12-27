#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // O(nlon)

        vector<long long> lastAvailabelAt(
            n, 0);                       // Room no i will be last available
        vector<int> roomUsedCount(n, 0); // Room i used how many times

        for (vector<int>& meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            bool found = false;

            long long earlyEndRoomTime = LLONG_MAX;
            int earlyRoom = 0;
            // O(n*m)+O(nlogn)
            for (int room = 0; room < n; room++) { // O(n)
                if (lastAvailabelAt[room] <= start) {
                    lastAvailabelAt[room] =
                        end; // Current meeting will finish at end
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }

                if (lastAvailabelAt[room] < earlyEndRoomTime) {
                    earlyEndRoomTime = lastAvailabelAt[room];
                    earlyRoom = room;
                }
            }

            if (!found) {
                // Pick that room that will end first
                lastAvailabelAt[earlyRoom] += duration;
                roomUsedCount[earlyRoom]++;
            }
        }
        int resultRoom = -1;
        int maxUse = 0;

        for (int room = 0; room < n; room++) {
            if (roomUsedCount[room] > maxUse) {
                resultRoom = room;
                maxUse = roomUsedCount[room];
            }
        }

        return resultRoom;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> meetings ={{0,10},{1,5},{2,7},{3,4}};
    cout << sol.mostBooked(2,meetings) << endl;
}
    