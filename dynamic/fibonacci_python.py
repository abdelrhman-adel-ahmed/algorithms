#using memoization
"""
we can also use list 
the goal is to stor the values of each return after the function return and if we call the same brach again
we use the stored value
"""
cach={}
def fib(x):
    if(x<=1):
        return x
    if x in cach:
        return cach[x]
    value= fib(x-1)+fib(x-2)
    cach[x]=value
    return value
print(fib(100)) 

______________________________________________________________________________________________
__________or you can use lru_cach__________

from functools import lru_cache
# lru --> least recently used cache 

@lru_cache(maxsize=1000) #inital size 100
def fib(x):
    if(x <=1):
        return x
    else: return fib(x-2)+fib(x-1)
