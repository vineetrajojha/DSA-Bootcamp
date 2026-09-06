class Solution:
    def pivotIndex(self, nums):

        totalSum = sum(nums)

        leftSum = 0
        rightSum = totalSum

        for i in range(len(nums)):

            rightSum -= nums[i]

            if leftSum == rightSum:
                return i

            leftSum += nums[i]

        return -1