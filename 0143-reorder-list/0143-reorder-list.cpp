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
    void reorderList(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,j=arr.size()-1;
        int cnt=0;
        temp=head;
        while(temp){
            if(cnt%2==0)temp->val=arr[i],cnt++,i++;
            else temp->val=arr[j],cnt++,j--;
            temp=temp->next;
        }
       
    }
};