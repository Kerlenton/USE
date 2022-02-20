from functools import lru_cache

def moves(h):
    heap, mymove, oppmove = h

    if (mymove == -1):
        return (heap + 1, oppmove, 1), (heap + 2, oppmove, 2), (heap * 2, oppmove, 0)
    if (mymove == 0):
        return (heap + 1, oppmove, 1), (heap + 2, oppmove, 2)
    if (mymove == 1):
        return (heap + 2, oppmove, 2), (heap * 2, oppmove, 0)
    if (mymove == 2):
        return (heap + 1, oppmove, 1), (heap * 2, oppmove, 0)

@lru_cache(None)

def f(h):
    if (h[0] >= 21):
        return 'END'
    if (any(f(m) == 'END' for m in moves(h))):
        return 'WIN1'
    if (all(f(m) == 'WIN1' for m in moves(h))):
        return 'LOSE1'
    if (any(f(m) == 'LOSE1' for m in moves(h))):
        return 'WIN2'
    if (all(f(m) == 'WIN1' or f(m) == 'WIN2' for m in moves(h))):
        return 'LOSE2'
    if (any(f(m) == 'LOSE2' for m in moves(h))):
        return 'WIN3'
    
    

for i in range(1, 23):
    h = i, -1, -1
    print(i, f(h))
