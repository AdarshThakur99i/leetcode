class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n, 0);

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Free rooms (sorted by room number)
        priority_queue<int, vector<int>, greater<>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);

        // Busy rooms (sorted by end time)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            // Free up rooms
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                busyRooms.push({end, room});
                count[room]++;
            } else {
                auto [next_free_time, room] = busyRooms.top(); busyRooms.pop();
                long long duration = end - start;
                busyRooms.push({next_free_time + duration, room});
                count[room]++;
            }
        }

        // Find the most booked room
        int maxCount = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                res = i;
            }
        }
        return res;
    }
};
