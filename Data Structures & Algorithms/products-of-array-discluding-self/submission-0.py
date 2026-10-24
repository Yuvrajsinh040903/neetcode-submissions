class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod, zero_count = 1, 0
        for i in nums:
            if i:
                prod = prod*i
            else:
                zero_count+=1

        if zero_count>1:
            return [0]*len(nums)

        res=[]
        for i in nums:
            if zero_count:
                res.append(0) if i else res.append(prod)
            else:
                res.append(prod//i)

        return res
