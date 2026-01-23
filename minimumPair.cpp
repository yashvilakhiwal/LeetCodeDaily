class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        
        struct Node {
            long long value; 
            Node* prev;
            Node* next;
        };
        
        vector<Node*> nodes(n);
        for(int i = 0; i < n; i++) {
            nodes[i] = new Node{(long long)nums[i], nullptr, nullptr};
            if(i > 0) {
                nodes[i]->prev = nodes[i-1];
                nodes[i-1]->next = nodes[i];
            }
        }
        
        int inversions = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i+1]) inversions++;
        }
        
        if(inversions == 0) return 0;
        
        using Pair = pair<long long, Node*>;  
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        
        for(int i = 0; i < n - 1; i++) {
            pq.push({(long long)nums[i] + nums[i+1], nodes[i]});
        }
        
        int operations = 0;
        
        set<Node*> deleted;
        
        while(inversions > 0) {
            auto [sum, left] = pq.top();
            pq.pop();
            
            Node* right = left->next;
            
            if(deleted.count(left) || !right || deleted.count(right)) continue;
            if(left->value + right->value != sum) continue;
            
            Node* prevNode = left->prev;
            Node* nextNode = right->next;
            if(prevNode && !deleted.count(prevNode) && prevNode->value > left->value) 
                inversions--;
            if(left->value > right->value) 
                inversions--;
            if(nextNode && !deleted.count(nextNode) && right->value > nextNode->value) 
                inversions--;
            
            
            left->value += right->value;   
            left->next = nextNode;
            if(nextNode) nextNode->prev = left;
            
            deleted.insert(right);
            
            if(prevNode && !deleted.count(prevNode) && prevNode->value > left->value) 
                inversions++;
            if(nextNode && !deleted.count(nextNode) && left->value > nextNode->value) 
                inversions++;
            
            if(prevNode && !deleted.count(prevNode)) {
                pq.push({prevNode->value + left->value, prevNode});
            }
            if(nextNode && !deleted.count(nextNode)) {
                pq.push({left->value + nextNode->value, left});
            }
            
            operations++;
        }
        
        return operations;
    }
};