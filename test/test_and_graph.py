# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_and_graph.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 10:18:40 by adi-stef          #+#    #+#              #
#    Updated: 2023/04/03 12:26:13 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
from time import perf_counter
from random import sample
import subprocess as sub
import numpy as np

MAX = 2147483647
MIN = -2147483648
P = "./push_swap"
C = "./checker"

def test100(number_of_tests, check): # 113.34s for 50000
    start = perf_counter()
    n = number_of_tests
    while (n > 0):
        abc = " ".join([str(i) for i in sample(range(MIN, MAX), 100)])
        n -= 1
        if (check and sub.getoutput(f'{P} {abc} | {C} {abc}') != 'OK'): print(abc, '\n'); break
        sub.getoutput(f'{P} {abc} | wc -l | grep -o "[0-9]\+" >> Moves/moves11.txt')
    end = perf_counter()
    print(f"Time [100] [{number_of_tests}]: {round(end - start, 2)}s")

def test500(number_of_tests, check): # 1108.01s for 15000
    start = perf_counter()
    n = number_of_tests
    while (n > 0):
        abc = " ".join([str(i) for i in sample(range(MIN, MAX), 500)])
        n -= 1
        if (check and sub.getoutput(f'{P} {abc} | {C} {abc}') != 'OK'): print(abc, '\n'); break
        sub.getoutput(f'{P} {abc} | wc -l | grep -o "[0-9]\+" >> Moves/moves51.txt')
    end = perf_counter()
    print(f"Time [500] [{number_of_tests}]: {round(end - start, 2)}s")

# test100(50000, 0)
# test500(25000, 0)

with open("Moves/moves11.txt", 'r') as f:
    nums = f.readlines()
nums = [int(i.replace('\n', '')) for i in nums]
print(f"Size: 100\nTests: {len(nums)}\nMax: {max(nums)}\nMin: {min(nums)}\nAvg: {sum(nums)//len(nums)}\n")
with open("Moves/moves51.txt", 'r') as f:
    nums = f.readlines()
nums = [int(i.replace('\n', '')) for i in nums]
print(f"Size: 500\nTests: {len(nums)}\nMax: {max(nums)}\nMin: {min(nums)}\nAvg: {sum(nums)//len(nums)}\n")

# for i in range(1, executables + 1):
#     with open(f"Moves/moves{i}.txt", 'r') as f:
#         nums = (f.readlines())
#     nums = [int(i.replace('\n', '')) for i in nums]
#     print(f"\npush_swap{i}\nMax: {max(nums)}\nMin: {min(nums)}\nAvg: {int(sum(nums)/len(nums))}\nColor: {colors[i]}")
#     # nums = [int(sum(nums)/len(nums)), max(nums)]
#     ypoints = np.array(nums)
#     # xpoints = np.array(range(1, len(nums) + 1))
#     plt.plot(ypoints, c = )

# plt.xlabel("test number")
# plt.ylabel("moves")

# plt.show()