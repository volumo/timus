l = []
i = int(raw_input())
for j in range(i):
	l.append(int(raw_input()))

l.sort()
raw_input()

i = int(raw_input())
for j in range(i):
	n = int(raw_input())
	print l[n-1]

