class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        N = len(nums)
        set_results = set()
        n = []
        p = []
        zeros = []
        
        for i in range(N):
            if nums[i] < 0:
                n.append(nums[i])
            elif nums[i] > 0:
                p.append(nums[i])
            else:
                zeros.append(0)
        
        n_set = set(n)
        p_set = set(p)

        # If there is at least one zero, add the pairs of negative and positives that sum to zero
        zeros_length = len(zeros)
        if zeros_length != 0:
            for neg in n_set:
                if -neg in p_set:
                    set_results.add((neg, 0, -neg))

        # If there are at least three zeros, add the [0,0,0]
        if zeros_length >= 3:
            set_results.add((0,0,0))

        # check for the triplets
        for i in range(len(n) - 1):
            for j in range(i+1, len(n)):
                if -(n[i]+n[j]) in p_set:
                    set_results.add(tuple(sorted([n[i], n[j], -(n[i]+n[j])])))

        for i in range(len(p) - 1):
            for j in range(i+1, len(p)):
                if -(p[i]+p[j]) in n_set:
                    set_results.add(tuple(sorted([p[i], p[j], -(p[i]+p[j])])))

        return set_results
