/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(!n) return nullptr;

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;
        
        for(int i = 0; i < n; i++) {
            if(lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }
        ListNode* temp = nullptr;

        if(!pq.empty()){
            auto p = pq.top(); pq.pop();
            temp = p.second;
            if(temp->next) pq.push({temp->next->val, temp->next});
        }

        auto ans = temp;

        while(!pq.empty()){

            auto [val, list] = pq.top(); pq.pop();

                ans->next = list;
                ans = ans->next;

            if(list->next) {
            pq.push({list->next->val, list->next});
        }
        }

        return temp;
        
    }
};