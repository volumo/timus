def mn(i):
    if (i == 1):
        return [1]
    elif (i == 0):
        return [10]
    else:
        j = []
        m = 0
        while (i != 1):
            ap = False
            for m in range(9,1,-1):
                if (i % m == 0):
                    j.append(m)
                    i /= m
                    ap = True
                    break
            if not ap:
                j = None
                break
        return j

r = mn(int(input()))
if (r is None):
    print "-1"
else:
    r.sort()
    print "".join([str(x) for x in r])

