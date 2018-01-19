m,n = 0,''
a = sorted(input().lower())
b = sorted(set(a))
for i in b:
	if i >= 'a' and i <= 'z':
		if a.count(i) > m:
			n = i
			m = a.count(i)
print(n+' '+str(m))