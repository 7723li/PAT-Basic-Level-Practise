def test():
  pa,pb='',''
  la = input().split()
  a,da,b,db=la[0],la[1],la[2],la[3]
  for i in a:
    if da == i:
      pa += da
  for i in b:
    if db == i:
      pb += db
  if pa:
    pa = int(pa)
  else:
    pa=0
  if pb:
    pb = int(pb)
  else:
    pb=0
  print(pa+pb)
test()