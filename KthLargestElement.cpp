class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {       
       
        /*Approach 1: sort all the elements in nums and return (index - k)th element 
        TC: O(nlogn)
        SC:O(nlogn) underhood implementation of c++ std::sort()

        1 2 3 5 8
        0 1 2 3 4
        int n=nums.size(); 
        sort(nums.begin(), nums.end());
        return nums[n-k];--------------------------------------------------------*/

      /*  Approach 2: ------------------------------------------------------------
        create a max heap structure and remove k elements and return the last element 
        TC: O(nlogn)
        SC: O(n)
        priority_queue<int> pq;
        for(auto n: nums)
        {
            pq.push(n);
        }
        while(k>1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
        ------------------------------------------------------------------------*/


        //Approach 3: optimal reduce time to klogk and space to k by only holding 
        // k elements in the PQ ---> catch here is to use min heap because we want "LARGEST"
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            while(pq.size()>k)
            {
                pq.pop();
            }

        }
        return pq.top();
        
    }
};


