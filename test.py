from typing import List


class Solution:
    def __init__(self):
        pass
        self.res_final = 0

    def amar(
            self,
            n,
            costs,
            partial_cost,
            result_array,
            current_index,
            city_a_pending,
            city_b_pending,
    ):
        if city_a_pending == 0 and city_b_pending == 0:
            # result_array.append(partial_cost[::])
            temp = 0
            for i in partial_cost[::]:
                temp = temp + i

            self.res_final = min(
                self.res_final, temp
            )
            return
        temp = 0
        for i in partial_cost[::]:
            temp = temp + i
        if self.res_final < temp:
            return

        if current_index >= len(costs) - 1:
            return
        if city_a_pending <= 0 and city_b_pending <= 0:
            return
        if city_a_pending > 0 and city_b_pending <= 0:
            partial_cost.append(costs[current_index + 1][0])
            self.amar(
                n,
                costs,
                partial_cost,
                result_array,
                current_index + 1,
                city_a_pending - 1,
                city_b_pending,
            )
            partial_cost.pop()
        elif city_b_pending > 0 and city_a_pending <= 0:
            partial_cost.append(costs[current_index + 1][1])
            self.amar(
                n,
                costs,
                partial_cost,
                result_array,
                current_index + 1,
                city_a_pending,
                city_b_pending - 1,
            )
            partial_cost.pop()
        elif city_b_pending > 0 and city_a_pending > 0:
            partial_cost.append(costs[current_index + 1][1])
            self.amar(
                n,
                costs,
                partial_cost,
                result_array,
                current_index + 1,
                city_a_pending,
                city_b_pending - 1,
            )
            partial_cost.pop()
            partial_cost.append(costs[current_index + 1][0])
            self.amar(
                n,
                costs,
                partial_cost,
                result_array,
                current_index + 1,
                city_a_pending - 1,
                city_b_pending,
            )
            partial_cost.pop()

    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        res_final1 = 0
        for i in range(0, len(costs), 1):
            res_final1 = res_final1 + costs[i][0]
        self.res_final = res_final1
        result_array = []
        n = len(costs) // 2  # no of people going to each city
        partial_cost = []  # total cost before the code start of that flow
        partial_cost.append(costs[0][0])
        self.amar(n, costs, partial_cost, result_array, 0, n - 1, n)
        partial_cost = []
        partial_cost.append(costs[0][1])
        self.amar(n, costs, partial_cost, result_array, 0, n, n - 1)

        # finalres = 999999
        # for i in result_array:
        #     temp = 0
        #     for j in i:
        #         temp = temp + j
        #     finalres = min(finalres, temp)
        return self.res_final


ty = Solution()
costs = [[393, 874], [299, 93], [947, 491], [214, 782], [25, 158], [666, 163], [547, 293], [653, 291], [922, 106],
         [294, 479], [79, 559], [579, 933], [433, 507], [75, 686], [420, 508], [813, 256], [613, 936], [192, 540],
         [463, 762], [784, 881], [440, 260], [176, 655], [532, 263], [890, 437], [553, 516], [880, 668]]
res = ty.twoCitySchedCost(costs)
print(res)
