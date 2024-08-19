class Solution:

    def betterCompression(self, compressed: str) -> str:
        my_dict = {}
        counter_string = 0

        counter_digit_first = 1
        counter_digit_second = 1

        while counter_string < len(compressed):
            "pass"
            # we need to calculate counter_string counter_digit_first counter_digit_second and use them
            counter_digit_first = counter_string + 1
            for i in range(counter_digit_first, len(compressed), 1):
                if compressed[i].isdigit() is True:
                    counter_digit_second = i
                else:
                    break
            new_counter_string = counter_digit_second + 1
            if compressed[counter_string] not in my_dict:
                my_dict[compressed[counter_string]] = int(
                    compressed[counter_digit_first:counter_digit_second + 1:1])
            else:
                my_dict[compressed[counter_string]] = my_dict[compressed[counter_string]] + int(
                    compressed[counter_digit_first:counter_digit_second + 1:1])
            counter_string = new_counter_string
        amar45 = list(my_dict.keys())
        amar45.sort()
        resamar = ""
        for i in amar45:
            resamar = resamar + str(i) + str(my_dict[i])

        return resamar


fff = Solution()
resss = fff.betterCompression("a3c9b2c1")
print(resss)
