#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<long long,int> P;


    int mostBooked(int n, vector<vector<int>> &meetings)
    {

        sort(meetings.begin(), meetings.end()); // O(nlon)

        vector<int> roomUsedCount(n, 0); // Room i used how many times

        priority_queue<P,vector<P>,greater<P>> usedRooms;
        priority_queue<int,vector<int>,greater<int>> availableRooms;

        for(int room = 0 ;room <n;room++){
            availableRooms.push(room);//Filling all room in available room
        }

        for(vector<int>& meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            bool found = false;

            while(!usedRooms.empty() && usedRooms.top().first<=start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }

            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end,room});
                roomUsedCount[room]++;
            }else{//We dont have any room available now. Pick earliest one
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime+duration,room});
                roomUsedCount[room]++;
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
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << sol.mostBooked(2, meetings) << endl;
}
