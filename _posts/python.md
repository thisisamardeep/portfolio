need to see how to rteverse a string in part
how to slice and keep copies and replace in part


python slicing examples

slice has 3 parameters start,stop,step

start is the index included
stop is not included
step is just step

Slice creates a new object


er = [2, 3, 4, 5, 6]

test = er[0:2:1]
print(test)
[2, 3]
print(id(er) != id(test))
True

er = [2, 3, 4, 5, 6]

test = er[::-1]  --> full reverse and new object
print(test)

[6, 5, 4, 3, 2]

er = [2, 3, 4, 5, 6]
rrt = er.reverse() --> inplace reverse and return none


Very tricky to change the paramter name in place in python
.If you create a local varialbe with same name as paramter name.
you override it.

Python has something called integer divisoon.
It is basically integer floor division.
so 5// 2 gives 2
and -5 //2 gives -3

cpp also gives the result as integer but it is not floor division.It just truncates the fractional part
    std::cout << 5 / 2 << std::endl; result 2
    std::cout << -5 / 2 << std::endl; wresul 2