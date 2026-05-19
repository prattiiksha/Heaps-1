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
        
        /*Approach 1: take all the lists nodes values and sort them 
        TC: O(nlogn)
        SC:O(n) */
        /*vector<int> values;
        for(ListNode* node : lists)
        {
            while(node!=nullptr)
            {
                values.push_back(node->val);
            }
        }
        sort(values.begin(), values.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* tail=dummy;

        for(auto n: values)
        {
            tail->next=new ListNode(n);
            tail=tail->next;
        }

        return dummy->next; memory limit exceeded*/

        //Approach 2: merge 2 lists at a time 
        //TC: O(Nk)
        //SC: O(1)
      /*  ListNode* dummy = nullptr;
        for(int i=0;i<lists.size();i++) -------------------------------------------------------
        {
            dummy=Merge(dummy, lists[i]);
        }
        return dummy;
    }
    ListNode* Merge(ListNode* head1, ListNode* head2)
    {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(head1!=nullptr and head2!=nullptr)
        {
            if(head1->val<=head2->val)
            {
                tail->next=head1;
                head1=head1->next;
            }
            else
            {
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
            
        }
        if (head1 != nullptr) 
                tail->next = head1;
        if (head2 != nullptr) 
                tail->next = head2;
        return dummy.next;
    }---------------------------------------------*/

    //Approach 3: Heaps for the rescue 
    //TC:  O(N log k)
    //SC: O(k)
    priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push({node->val, node});
            }
        }
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top().second;
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next != nullptr) {
                pq.push({curr->next->val, curr->next});
            }
        }

        return dummy.next;
    }
};
