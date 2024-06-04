from typing import List

from typing import List


class Solution:
    def amar(self, str1, str2) -> bool:

        list1 = list(str1)
        list2 = list(str2)
        count_of_matches = 0
        count_of_differences = 0
        for i in range(0, len(list1), 1):
            if list1[i] == list2[i]:
                count_of_matches = count_of_matches + 1
            else:
                count_of_differences = count_of_differences + 1
        if count_of_differences == 0 or count_of_differences == 2:
            print(str1)
            print(str2)
            print("True")
            return True
        else:
            print(str1)
            print(str2)
            print("False")
            return False

    def numSimilarGroups(self, strs: List[str]) -> int:
        if len(strs) == 0:
            return 0
        final_groups: List = []
        final_groups.append([strs[0]])
        for curr_string in strs[1:len(strs):1]:
            found = False
            index_found = []
            for i in range(0, len(final_groups), 1):

                for j in range(0, len(final_groups[i]), 1):
                    str1 = curr_string
                    str2 = final_groups[i][j]
                    res = self.amar(str1, str2)
                    if res:
                        found = True
                        final_groups[i].append(curr_string)
                        index_found.append(i)
                        # break
                    else:
                        pass

            if found:
                if len(index_found) == 1:
                    pass
                else:
                    for k in index_found:
                        final_groups[k].append(curr_string)

            else:
                # print(curr_string)
                final_groups.append([curr_string])

        return len(final_groups)


sd = Solution()

eee = sd.numSimilarGroups(
    ["kccomwcgcs", "socgcmcwkc", "sgckwcmcoc", "coswcmcgkc", "cowkccmsgc", "cosgmccwkc", "sgmkwcccoc", "coswmccgkc",
     "kowcccmsgc", "kgcomwcccs"])
print(eee)
