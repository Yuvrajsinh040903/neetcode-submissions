class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # 1. Global Product
        # prod, zero_count = 1, 0
        # for i in nums:
        #     if i:
        #         prod = prod*i
        #     else:
        #         zero_count+=1

        # if zero_count>1:
        #     return [0]*len(nums)

        # res=[]
        # for i in nums:
        #     if zero_count:
        #         res.append(0) if i else res.append(prod)
        #     else:
        #         res.append(prod//i)

        # return res

        # Prefix suffix
        # n = len(nums)
        # pre, post, res = [0]*n, [0]*n, [0]*n

        # pre[0] = post[n-1] = 1

        # for i in range(1,n):
        #     pre[i] = pre[i-1]*nums[i-1]
        # for i in range(n-2,-1,-1):
        #     post[i] = post[i+1]*nums[i+1]
        # for i in range(0,n):
        #     res[i] = pre[i]*post[i]

        # return res

        # Prefix Suffix optimal

        n, res = len(nums), []
        res.append(1)
        for i in range(1,n):
            res.append(res[i-1]*nums[i-1])

        post=1
        for i in range(n-1, -1, -1):
            res[i] *= post
            post *= nums[i]
        return res
