class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int: 
        if sum(gas)<sum(cost): 
            return -1 
        
        total=0 
        ans=0 

        for i in range(len(gas)):   #len of gas is equal to cost 
            total += (gas[i]-cost[i])
            if total<0: 
                total=0      #reset total to 0 if tot becoms -ve
                ans=i+1      #we know for sure there exist an ans, as sum(gas)>=sum(cost) 
        
        return ans 
