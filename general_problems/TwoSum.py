nums = [2, 7, 11, 15]
target = 9

def twoSum(nums, target):
    for x in range(0,len(nums)):
        for i in range(x+1,len(nums)):
            if(nums[x] + nums[i] == target):
                return [x, i]

print(twoSum(nums, target))