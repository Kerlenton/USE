from functools import lru_cache

def moves(h):
    a, b = h
    if a < 2:
        return (a, b // 2), (a, b - 1)
    elif b < 2:
        return (a // 2, b), (a - 1, b)
    elif a > 1 and b > 1:
        return (a, b // 2), (a, b - 1), (a // 2, b), (a - 1, b)
    
@lru_cache(None)

def f(h):
    if (sum(h) <= 18):
        return 'СР'
    
    elif (h > 60):
        return 'П1'
    
    elif any(f(m) == 'СР' for m in moves(h)):
        return 'П1'
        
    elif all(f(m) == 'П1' for m in moves(h)):
        return 'В1'
    
    elif any(f(m) == 'В1' for m in moves(h)):
        return 'П2'
    
    elif all(f(m) == 'П1' or f(m) == 'П2' for m in moves(h)):
        return 'В2'

for s in range(1, 118):
    print(s, '->', f(s))
