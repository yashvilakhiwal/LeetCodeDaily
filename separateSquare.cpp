class Solution {
    struct Event {
        long long y, x1, x2;
        int type;
        bool operator<(const Event& e) const {
            if (y != e.y) return y < e.y;
            return type > e.type;
        }
    };
    
    struct SegmentTree {
        vector<int> cnt;
        vector<long long> len;
        vector<long long> coords;
        int n;
        
        SegmentTree(vector<long long>& x) : coords(x) {
            n = x.size() - 1;
            cnt.resize(4 * n);
            len.resize(4 * n);
        }
        
        void update(int v, int l, int r, int ql, int qr, int val) {
            if (ql >= qr) return;
            if (l == ql && r == qr) {
                cnt[v] += val;
            } else {
                int m = (l + r) / 2;
                update(2*v, l, m, ql, min(qr, m), val);
                update(2*v+1, m, r, max(ql, m), qr, val);
            }
            
            if (cnt[v] > 0) {
                len[v] = coords[r] - coords[l];
            } else if (l + 1 == r) {
                len[v] = 0;
            } else {
                len[v] = len[2*v] + len[2*v+1];
            }
        }
        
        long long query() {
            return len[1];
        }
    };
    
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        set<long long> xSet;
        
        for (auto& sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});
            xSet.insert(x);
            xSet.insert(x + l);
        }
        
        sort(events.begin(), events.end());
        
        vector<long long> xCoords(xSet.begin(), xSet.end());
        map<long long, int> xIndex;
        for (int i = 0; i < xCoords.size(); i++) {
            xIndex[xCoords[i]] = i;
        }
        
        SegmentTree seg(xCoords);
        
        vector<pair<long long, long long>> strips;
        
        int i = 0;
        while (i < events.size()) {
            long long currY = events[i].y;
            
            while (i < events.size() && events[i].y == currY) {
                int l = xIndex[events[i].x1];
                int r = xIndex[events[i].x2];
                seg.update(1, 0, xCoords.size() - 1, l, r, events[i].type);
                i++;
            }
            
            long long width = seg.query();
            strips.push_back({currY, width});
        }
        
        long long totalArea = 0;
        for (int i = 0; i < strips.size() - 1; i++) {
            long long height = strips[i + 1].first - strips[i].first;
            totalArea += height * strips[i].second;
        }
        
        if (totalArea == 0) return 0.0;
        
        double targetArea = totalArea / 2.0;
        long long cumArea = 0;
        
        for (int i = 0; i < strips.size() - 1; i++) {
            long long y1 = strips[i].first;
            long long y2 = strips[i + 1].first;
            long long width = strips[i].second;
            long long stripArea = (y2 - y1) * width;
            
            if (cumArea + stripArea >= targetArea) {
                if (width == 0) {
                    cumArea += stripArea;
                    continue;
                }
                
                double remaining = targetArea - cumArea;
                double ratio = remaining / (double)stripArea;
                return y1 + ratio * (y2 - y1);
            }
            
            cumArea += stripArea;
        }
        
        return strips.back().first;
    }
};