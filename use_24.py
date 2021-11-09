f = open('24.txt')
s = f.readline()
sub = s.split('D')
m = 0
for i in range(len(sub)-1):
        m = max(m, len(sub[i] + sub[i+1] + 'D'))

print(m)
