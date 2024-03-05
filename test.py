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


def amar(inp, start, end) -> None:
    print(start)
    print(end)
    if start == end:
        return
    # if start == 0 and end == 1:
    #     return
    middle = (start + end) // 2
    amar(inp, start, middle)
    amar(inp, middle + 1, end)


def driver(inp):
    amar(inp, 0, len(inp) - 1)


driver(sd)
