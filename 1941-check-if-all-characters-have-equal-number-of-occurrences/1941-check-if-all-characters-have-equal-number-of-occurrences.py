class Solution:
    def areOccurrencesEqual(self, st: str) -> bool:
        freq = {}
        temp = set()
        
        for s in st:
            freq[s] = freq.get(s, 0) + 1

        for value, count in freq.items():
            temp.add(count)

        if len(temp) == 1: 
            return True
        return False
