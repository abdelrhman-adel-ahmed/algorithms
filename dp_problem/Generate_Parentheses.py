n=2
result=[]
def generate(iner=[],close=0,open=0):
    if len(iner) == n*2:
        result.append("".join(iner))
        return
    if open <n:
        iner.append('(')
        generate(iner,close,open+1)
        iner.pop()
    if close <open:
        iner.append(')')
        generate(iner,close+1,open)
        iner.pop()

generate()
print(result)
