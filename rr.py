sd = [3, 4, 5, 6, 7, 8]
sd1 = sd[0:3:1][::-1]
sd12 = sd[::-1]
print(sd)
print(sd1)
print(id(sd))
print(id(sd1))
print(sd12)
