from functools import lru_cache

def moves(h):
    return h + 1, h + 2, h * 3

@lru_cache(None)

def f(h):
    '''def next(*condition):
        return (f(m) in condition for m in moves(h))'''
        
    next = lambda *condition: (f(m) in condition for m in moves(h))
    
    if (h > 64):
        return 'СР'
    elif any(next('СР')):
        return 'П1'
    elif all(next('П1')):
        return 'В1'
    elif any(next('В1')):
        return 'П2'
    elif all(next('П1', 'П2')):
        return 'В2'

for i in range(1, 65):
    print(i, '->', f(i))
