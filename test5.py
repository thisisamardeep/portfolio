class Solution:

    def find_left(self, s, i):
        res = i - 1
        if res == 0:
            return res
        while True:
            if res == 0:
                return res
            if s[res] not in ["*", "+", "-", "/"]:
                res = res - 1
            elif res == 0:
                return res
            else:
                return res + 1

    def find_right(self, s, i):
        res = i + 1
        if res == len(s) - 1:
            return res
        while True:
            if res == len(s) - 1:
                return res
            if s[res] not in ["*", "+", "-", "/"]:
                res = res + 1
            elif res == len(s) - 1:
                return res
            else:
                return res - 1

    def calculate(self, s: str) -> int:
        s = s.replace(" ", "")

        while "+" in s or "-" in s or "-" in s or "/" in s:
            pass
        while True:
            if "*" in s:
                index = s.find("*")
                left = self.find_left(s, index)
                right = self.find_right(s, index)

                l1 = s[left:index:1]
                r1 = s[index + 1: right + 1: 1]

                l11 = s[0:left:1]
                r11 = s[right + 1:: 1]

                s = l11 + str(int(l1) * int(r1)) + r11

            else:
                break
        while True:
            if "/" in s:
                index = s.find("/")
                left = self.find_left(s, index)
                right = self.find_right(s, index)

                l1 = s[left:index:1]
                r1 = s[index + 1: right + 1: 1]

                l11 = s[0:left:1]
                r11 = s[right + 1:: 1]

                s = l11 + str(int(l1) // int(r1)) + r11

            else:
                break

        while True:
            if "-" in s:
                if s[0] == "-":
                    break
                index = s.find("-")
                left = self.find_left(s, index)
                right = self.find_right(s, index)

                l1 = s[left:index:1]
                r1 = s[index + 1: right + 1: 1]

                l11 = s[0:left:1]
                r11 = s[right + 1:: 1]

                s = l11 + str(int(l1) - int(r1)) + r11

            else:
                break
        while True:
            if "+" in s:
                index = s.find("+")
                left = self.find_left(s, index)
                right = self.find_right(s, index)

                l1 = s[left:index:1]
                r1 = s[index + 1: right + 1: 1]

                l11 = s[0:left:1]
                r11 = s[right + 1:: 1]

                s = l11 + str(int(l1) + int(r1)) + r11

            else:
                break
        return int(s)


fg = Solution()
res = fg.calculate("2+3-4")
print(res)
