def isPalindromic(a):
    l = len(a)
    for i in range(0,int(l/2)):
        if a[i] != a[l - i - 1]:
            return False
    return True


def test():
    time = 0
    a = input()
    while True:
        if time == 10:
            print('Not found in 10 iterations.')
            break

        b = reversed(a)
        c = ''
        while True:
            try:
                c += next(b)
            except:
                break
        d = str(int(a) + int(c))
        print('{} + {} = {}'.format(a, c, d))
        if(isPalindromic(d)):
            print('{} is a palindromic number.'.format(d))
            break
        else:
            a = d
            time += 1

test()
