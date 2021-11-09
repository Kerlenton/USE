from itertools import *
k = 1

for x in product('АВОРТ', repeat = 4):
    s = ''.join(x)
    if (s == 'ТАРА'):
        print(k)
    
    k += 1
