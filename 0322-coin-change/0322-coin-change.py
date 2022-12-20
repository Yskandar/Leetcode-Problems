class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dico = {}
        mini = float('inf')

        if amount == 0:
            return 0
        
        for target in range(1, amount + 1):
            dico[target] = float('inf')

            for coin in coins:
                dico[coin] = 1
                if target - coin > 0 and dico[target - coin] != float('inf'):
                    dico[target] = min(dico[target], dico[target - coin] + 1)

        if dico[amount] == float('inf'):
            return -1
        else:
            return dico[amount]

                    
                