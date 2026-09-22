class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        freq = {}
        for num in arr:
            freq[num] = freq.get(num, 0) + 1
        
        temp = []
        for num, value in freq.items():
            temp.append(value)

        temp.sort()
        
        for i in range(len(temp) - 1):
            if temp[i] == temp[i + 1]: 
                return False

        return True
