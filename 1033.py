wrong = input()
Ipt = input()
for i in wrong:
	if i == '+':
		for j in range(65,90+1):
			Ipt = Ipt.replace(chr(j),'')
	else:
		Ipt = Ipt.replace(i,'')
		Ipt = Ipt.replace(i.lower(),'')
print(Ipt)

# 7+IE.
# 7_This_is_a_test.