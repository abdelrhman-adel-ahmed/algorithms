 def maxNumberOfBalloons(text: str) -> int:
        l=Counter(text)
        return min(l['b'],l['a'],l['l']//2,l['o']//2,l['n'])
