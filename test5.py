er = [2, 3, 4, 5, 6]

test = er[::-1]
rrt = er.reverse()
print(test)

[6, 5, 4, 3, 2]
print(id(test))
print(id(er))
print(rrt)