class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
       
        num_to_index = {}
        
        # First pass: Populate the dictionary
        for i, num in enumerate(nums):
            num_to_index[num] = i
        
        # Second pass: Check for the complement
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_to_index and num_to_index[complement] != i:
                return [i, num_to_index[complement]]
        
        return []