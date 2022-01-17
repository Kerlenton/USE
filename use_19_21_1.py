# Дима, тебе нельзя сюда смотреть

from functools import lru_cache

def moves(h):
    a, b = h
    return (a+1, b), (a, b+1), (a*4, b), (a, b*4)

@lru_cache(None)

def f(h):
    if (sum(h) >= 125):
        return 'СР'
    elif any(f(m) == 'СР' for m in moves(h)):
        return 'П1'
        
    elif all(f(m) == 'П1' for m in moves(h)):
        return 'В1'
    
    elif any(f(m) == 'В1' for m in moves(h)):
        return 'П2'
    
    elif all(f(m) == 'П1' or f(m) == 'П2' for m in moves(h)):
        return 'В2'

for s in range(1, 118):
    print(s, '->', f((7, s)))
