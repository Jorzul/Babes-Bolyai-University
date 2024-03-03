def addE(elem, rlist):
    if not rlist:
        return [elem]
    else:
        return [rlist[0]] + addE(elem, rlist[1:])


if __name__ == '__main__':
    list = [1, 2, 3, 4]
    e = 7

    new_list = addE(e, list)
    print(new_list)
