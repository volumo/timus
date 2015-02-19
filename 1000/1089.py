import sys

def eq(first, second):
	if len(first) != len(second):
		return "0"
	else:
		err = 0
		for i in range(len(first)):
			if first[i] != second[i]:
				err+=1
		if err == 1:
			return second
		else:
			return "0"

text = ""
for line in sys.stdin:
   text += line
j = text.split('#')
words = j[0].split('\n')


raw = j[1]
w2 = []
w = ''
a = ''
a2 = []

for u in raw:
	if u.isalpha():
		w += u
		if a != '':
			a2.append(a)
			a = ''
	else:
		a += u
		if w != '':
			w2.append(w)
			w = ''

if w != '':
	w2.append(w)
if a != '':
	a2.append(a)
	
a2.pop(0)

co = 0

for i in range(len(w2)):
	for q in words:
		s = eq(w2[i],q)
		if s != "0":
			w2[i] = s
			co += 1
res = ""
for i in range(len(w2) - 1):
	res+=w2[i] + a2[i]
res += w2[len(w2)-1] + a2[len(a2)-1]
print res,
print co
			
