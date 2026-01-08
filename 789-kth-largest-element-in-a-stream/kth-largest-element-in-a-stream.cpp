class KthLargest {
    //interger k
    int K;
    //defining min heap
    priority_queue<int , vector<int> , greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
         K = k;
    //Traverse all the elements in the array
    for(int i = 0; i< nums.size(); i++){
      //if min heap size is less than k add the cureent element
      if(pq.size() < K){
        pq.push(nums[i]);
      }
      else{
        //else if the top element is smaller than the current element 
        if(nums[i] > pq.top()){
          pq.pop(); //pop first
          pq.push(nums[i]); // Add the current element
        }
      }
    }
    }
    
    int add(int val) {
         // If the size of the queue is less than K
        if(pq.size() < K){
        pq.push(val);
        return pq.top();
       }  
         // If the smallest element is less than the element to be added
       if(val > pq.top()) {
        pq.pop();
        pq.push(val);
       }             
       //return the top
       return pq.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */