a = input().split(' ')
M, N, TOL = int(a[0]), int(a[1]), int(a[2])
pos = [-(M+1),-M,-(M-1),-1,1,M-1,M,M+1]

li = []
for i in range(N):
	a = input().replace('\t',' ').split(' ')
	for j in a:
		if j != '':
			li.append(int(j))

string = '{}: {}'
s = 0
for i in set(li):
	if li.count(i) == 1:
		a = li.index(i)
		flag = 1
		for j in pos:
			try:
				b = abs(i - li[a + j])
				if b <= TOL:
					flag = 0
					break
			except:
				pass
		if flag == 1:
			if s < 1:
				y = int(a / M)
				x = a - y * M
				x += 1
				y += 1
				string = string.format((x,y), i)
			s += 1

if s == 0:
	print('Not Exist')
elif s == 1:
	print(string)
else:
	print('Not Unique')