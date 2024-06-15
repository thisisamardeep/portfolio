from typing import List


class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        if len(sequence) == 1 and len(word) == 1 and word == sequence:
            return 1
        outer_counter = 0
        k = 0
        while outer_counter < len(sequence) - len(word) - 1:
            inner_counter = outer_counter
            while inner_counter < len(sequence) - 1:
                if (
                        sequence[
                        inner_counter: min(
                            inner_counter + len(word), len(sequence) - 1
                        ): 1
                        ]
                        == word
                ):
                    k = k + 1
                inner_counter = inner_counter + len(word)
            outer_counter = outer_counter + 1
        return k


sd = Solution()
res = sd.maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba")
print(res)
