from functools import lru_cache

def moves(h):
    return h*3, h*2, h+1
    
@lru_cache(None)

def f(h):
    if (36 <= h <= 60):
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
