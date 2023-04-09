# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 15:55:16 by adi-stef          #+#    #+#              #
<<<<<<< Updated upstream
#    Updated: 2023/04/02 18:56:53 by adi-stef         ###   ########.fr        #
=======
#    Updated: 2023/03/27 14:43:56 by adi-stef         ###   ########.fr        #
>>>>>>> Stashed changes
#                                                                              #
# **************************************************************************** #

import subprocess as sub
from random import sample
from time import perf_counter

MAX = 2147483647
MIN = -2147483648
P = "./push_swap"
C = "./checker"
tests = 0
error = 0
ok = 0
lko = []
comb = []

# test 2
if (sub.getoutput(f'{P} "{MAX} {MIN} | {C} {MAX} {MIN}') == "KO"): lko.append(f'{MAX} {MIN}')
if (sub.getoutput(f'{P} {MIN} {MAX} | {C} {MIN} {MAX}') == "KO"): lko.append(f'{MIN} {MAX}')
tests += 2
ok += 2 - len(lko)

# test 3
while (True):
    if (len(comb) == 6): break
    abc = ' '.join([str(i) for i in sample(range(MIN, MAX), 3)])
    if (abc in comb): continue
    comb.append(abc)
    out = sub.getoutput(f'{P} {abc} | {C} {abc}')
    if (out == "KO"): lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1
    else: print(out, abc, sep="\n"); exit(1)

tests += len(comb)
comb = []

# test 5
while (True):
    if (len(comb) == 120): break
    abc = ' '.join([str(i) for i in sample(range(MIN, MAX), 5)])
    if (abc in comb): continue
    comb.append(abc)
    out = sub.getoutput(f'{P} {abc} | {C} {abc}')
    if (out == "KO"): lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

tests += len(comb)
comb = []

# test 100
while (True):
    if (len(comb) == 500): break
    abc = ' '.join([str(i) for i in sample(range(MIN, MAX), 100)])
    if (abc in comb): continue
    comb.append(abc)
    out = sub.getoutput(f"{P} {abc} | {C} {abc}")
    if (out == "KO"): lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

tests += len(comb)
comb = []

# test 500
while (True):
    if (len(comb) == 50): break
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), 500)])
    if (abc in comb): continue
    comb.append(abc)
    out = sub.getoutput(f'{P} {abc} | {C} {abc}')
    if (out == "KO"): lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

tests += len(comb)
comb = []

# start = perf_counter()
# # test from 0 to 500
# for i in range(2, 501):
#     abc = " ".join([str(i) for i in sample(range(MIN, MAX), i)])
#     while (abc in comb):
#         abc = " ".join([str(i) for i in sample(range(MIN, MAX), i)])
#     comb.append(abc)
#     out = sub.getoutput(f'{P} {abc} | {C} {abc}')
#     if (out == "KO"): lko.append(abc)
#     elif (out == "Error"): error += 1
#     elif (out == "OK"): ok += 1
# end = perf_counter()
# tests += len(comb)

if (len(lko)):
    for i in lko: print(i)
print(f"Tests: {tests}")
print(f"OK: {ok}")
print(f"KO: {len(lko)}")
print(f"Error: {error}")
# print(f"Correct: {(tests - error - len(lko))/(tests - error)*100}%")
# print(f"Time to execute 498 tests (2-500 numbers): {round(end - start, 2)}")

# test n moves with 100 numbers
# moves = []
# comb = []
# n = 0
# start = perf_counter()
# while (42):
#     if (len(comb) == 10000): break
#     abc = " ".join([str(i) for i in sample(range(MIN, MAX), 100)])
#     if (abc in comb): continue
#     comb.append(abc)
#     out = sub.getoutput(f'{P} {abc} | wc -l | grep -o "[0-9]\+"')
#     if (int(out) > 700): n += 1
#     elif (int(out) < 200): print(abc, out, sep="\n"); exit(1)
#     try:
#         moves.append(int(out))
#     except:
#         print(abc, out, sep="\n"); exit(1)
# end = perf_counter()

# with open("nmoves1lis", "a") as f:
#     f.write("\n".join([str(i) for i in moves]))

# print(f"Number of tests with {len(comb[0].split())} pseudorandom numbers: {len(moves)}")
# print(f"Max moves for {len(comb[0].split())} numbers: {max(moves)}")
# print(f"Min moves for {len(comb[0].split())} numbers: {min(moves)}")
# print(f"Avg moves for {len(comb[0].split())} numbers: {round(sum(moves) / len(moves), 2)}")
# print(f"Moves > 700: {n}")
# print(f"Time: {round(end - start, 2)}s")

<<<<<<< Updated upstream
# moves = []
# comb = []
# n = 0
# start = perf_counter()
# while (42):
#     if (len(comb) == 500): break
#     abc = " ".join([str(i) for i in sample(range(MIN, MAX), 500)])
#     if (abc in comb): continue
#     comb.append(abc)
#     if (sub.getoutput(f'{P} {abc} | {C} {abc}') != "OK"): print(abc); exit(1)
#     out = sub.getoutput(f'{P} {abc} | wc -l | grep -o "[0-9]\+"')
#     if (int(out) > 5500): n += 1
#     elif (int(out) < 1000): print(abc, out, sep="\n"); exit(1)
#     try:
#         moves.append(int(out))
#     except:
#         print(abc, out, sep="\n"); exit(1)
# end = perf_counter()

# # with open("nmoves5lis", "w") as f:
# #     f.write("\n".join([str(i) for i in moves]))

# print(f"Number of tests with {len(comb[0].split())} numbers in input: {len(comb)}")
# print(f"Max moves for {len(comb[0].split())} numbers in input: {max(moves)}")
# print(f"Min moves for {len(comb[0].split())} numbers in input: {min(moves)}")
# print(f"Avg moves for {len(comb[0].split())} numbers in input: {round(sum(moves) / len(moves), 2)}")
# print(f"Moves > 5500: {n}")
# print(f"Time: {round(end - start, 2)}s\n")
# # print(comb[moves.index(max(moves))])
=======
moves = []
comb = []
n = 0
start = perf_counter()
while (42):
    if (len(comb) == 100): break
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), 500)])
    if (abc in comb): continue
    comb.append(abc)
    if (sub.getoutput(f'{P} {abc} | {C} {abc}') != "OK"): print(abc); exit(1)
    out = sub.getoutput(f'{P} {abc} | wc -l | grep -o "[0-9]\+"')
    if (int(out) > 5500): n += 1
    elif (int(out) < 1000): print(abc, out, sep="\n"); exit(1)
    try:
        moves.append(int(out))
    except:
        print(abc, out, sep="\n"); exit(1)
end = perf_counter()

# with open("nmoves5lis", "w") as f:
#     f.write("\n".join([str(i) for i in moves]))

print(f"Number of tests with {len(comb[0].split())} numbers in input: {len(comb)}")
print(f"Max moves for {len(comb[0].split())} numbers in input: {max(moves)}")
print(f"Min moves for {len(comb[0].split())} numbers in input: {min(moves)}")
print(f"Avg moves for {len(comb[0].split())} numbers in input: {round(sum(moves) / len(moves), 2)}")
print(f"Moves > 5500: {n}")
print(f"Time: {round(end - start, 4)}s\n")
# print(comb[moves.index(max(moves))])
>>>>>>> Stashed changes
