from recviz import recviz


@recviz
def fib(n):
    # base condition mimicking the first two numbers
    # in the sequence
    if n == 0: return 0
    if n == 1: return 1

    # every number is summation of the previous two
    return fib(n - 1) + fib(n - 2)


# fib(3)
sd = [1, 5, 11, 2]


def mergme(inp, start, middle, end):
    res = []
    first = inp[start: middle + 1: 1]
    second = inp[middle + 1:end + 1: 1]
    print(first)
    print(second)
    print(33333333333333)

    i = 0
    j = 0

    while i < len(first) or j < len(second):
        print(i)
        print(j)
        if i < len(first) and j < len(second):
            if first[i] <= second[j]:
                res.append(first[i])
                i = i + 1
            else:
                res.append(second[j])
                j = j + 1
        elif i < len(first) and j >= len(second):
            res.append(first[i])
            i = i + 1
        elif i >= len(first) and j < len(second):
            res.append(second[j])
            j = j + 1
    return res


def amar(inp, start, end) -> None:
    if start == end:
        return
    # if start == 0 and end == 1:
    #     return
    middle = (start + end) // 2
    amar(inp, start, middle)
    amar(inp, middle + 1, end)
    # print("========================")
    # print(start)
    # print(end)
    # print("========================")
    er = mergme(inp, start, middle, end)
    inp[start:end + 1:1] = er
    print(er)
    ty = 67
    # inp[start, end + 1, 1] =
    # print(inp[start:end:1])


def driver(inp):
    # mergeSort(inp, 0, len(inp) - 1)
    amar(inp, 0, len(inp) - 1)
    print(inp)


# driver(sd)
driver(sd)
