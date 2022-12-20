class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        cell_dic = {}
        for i in range(amount+1):
            cell_dic[i] = -1
        cell_dic[0] = 0
        for n in range(1,amount+1):
            num = {}
            for coin in coins:
                if n-coin>=0 and cell_dic[n-coin]!=-1:
                    num[coin] = cell_dic[n-coin] + 1
            if num == {}:
                cell_dic[n] = -1
            else:
                cell_dic[n] = min(num.values())
        return cell_dic[amount]

                    
                