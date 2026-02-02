class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long result = LLONG_MAX;
        
        multiset<int> selected;
        multiset<int> candidates;
        long long selectedSum = 0;
        
        for (int i = 1; i <= min(1 + dist, n - 1); i++) {
            selected.insert(nums[i]);
            selectedSum += nums[i];
        }
        
        while (selected.size() > k - 1) {
            auto it = prev(selected.end());
            selectedSum -= *it;
            candidates.insert(*it);
            selected.erase(it);
        }
        
        result = nums[0] + selectedSum;
        
        for (int i = 2; i + dist < n; i++) {
            int toAdd = nums[i + dist];
            int toRemove = nums[i - 1];
            
            candidates.insert(toAdd);
            
            if (selected.find(toRemove) != selected.end()) {
                selected.erase(selected.find(toRemove));
                selectedSum -= toRemove;
                
                auto it = candidates.begin();
                selected.insert(*it);
                selectedSum += *it;
                candidates.erase(it);
            } else {
                candidates.erase(candidates.find(toRemove));
            }
            
            while (!candidates.empty() && *candidates.begin() < *selected.rbegin()) {
                int minCand = *candidates.begin();
                int maxSel = *selected.rbegin();
                
                candidates.erase(candidates.begin());
                selected.erase(prev(selected.end()));
                
                candidates.insert(maxSel);
                selected.insert(minCand);
                
                selectedSum = selectedSum - maxSel + minCand;
            }
            
            result = min(result, nums[0] + selectedSum);
        }
        
        return result;
    }
};