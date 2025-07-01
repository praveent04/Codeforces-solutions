#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        // BFS with state (queue_index, time)
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        
        q.push({1, 0});
        visited.insert({1, 0});
        
        int ans = -1;
        
        while (!q.empty()) {
            auto [queue_idx, time] = q.front();
            q.pop();
            
            // Calculate our position in current queue at current time
            int my_position;
            if (queue_idx == 1) {
                // We started in queue 1 at position a[1]
                my_position = max(1, a[1] - time);
            } else {
                // We moved to this queue, so we joined when queue had max(0, a[queue_idx] - time) people
                // We became the last person, so our position was max(0, a[queue_idx] - time) + 1
                // After people left, our position is max(1, max(0, a[queue_idx] - time) + 1 - 1)
                my_position = max(1, max(0, a[queue_idx] - time));
            }
            
            if (my_position == 1) {
                ans = time;
                break;
            }
            
            if (time >= 1000) continue; // Upper bound to prevent infinite loop
            
            // Try staying in same queue
            if (visited.find({queue_idx, time + 1}) == visited.end()) {
                visited.insert({queue_idx, time + 1});
                q.push({queue_idx, time + 1});
            }
            
            // Try moving to adjacent queues
            for (int next_queue : {queue_idx - 1, queue_idx + 1}) {
                if (next_queue >= 1 && next_queue <= n) {
                    if (visited.find({next_queue, time + 1}) == visited.end()) {
                        visited.insert({next_queue, time + 1});
                        q.push({next_queue, time + 1});
                    }
                }
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
