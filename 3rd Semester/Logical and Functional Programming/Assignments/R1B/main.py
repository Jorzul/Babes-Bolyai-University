def concat(rlist1, rlist2):
    if not rlist1:
        return rlist2
    elif not rlist2:
        return rlist1
    else:
        return [rlist1[0]] + concat(rlist1[1:], rlist2)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    list1 = [1, 2, 3]
    list2 = [4, 5, 6]

    new_list = concat(list1, list2)
    print(new_list)
