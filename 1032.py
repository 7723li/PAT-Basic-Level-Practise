def test():
	d, num= {}, int(input())
	Max, MaxId = 0, ''
	for i in range(num):
		a = input().split()
		try:
			d[a[0]] += int(a[1])
		except KeyError:
			d[a[0]] = int(a[1])
		if d[a[0]] > Max:
			Max, MaxId = d[a[0]], a[0]
	print(MaxId+' '+str(Max))

test()

# 6
# 3 65
# 2 80
# 1 100
# 2 70
# 3 40
# 3 0