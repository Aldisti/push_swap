# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 15:55:16 by adi-stef          #+#    #+#              #
#    Updated: 2023/03/17 18:01:07 by lde-mich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import subprocess as sub
from random import sample
from time import time

MAX = 2147483647
MIN = -2147483648
P = "./push_swap"
C = "./checker_linux"
tests = 0
error = 0
ok = 0
lko = []
comb = []

# test 2
if (sub.getoutput(f'{P} "{MAX} {MIN} | {C} {MAX} {MIN}') == "KO"): lko.append(f'{MAX} {MIN}')
if (sub.getoutput(f'{P} {MIN} {MAX} | {C} {MIN} {MAX}') == "KO"): lko.append(f'{MIN} {MAX}')
tests += 2

# test 3
for a in range(100):
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
for _ in range(1000):
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
for _ in range(1000):
    if (len(comb) == 100): break
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
for _ in range(1000):
    if (len(comb) == 100): break
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), 500)])
    if (abc in comb): continue
    comb.append(abc)
    out = sub.getoutput(f'{P} {abc} | {C} {abc}')
    if (out == "KO"): lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

tests += len(comb)
comb = []

# test from 0 to 500
for i in range(2, 501):
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), i)])
    out = sub.getoutput(f'{P} {abc} | {C} {abc}')
    if (out == "KO"): lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

tests += len(comb)

if (len(lko)):
    for i in lko: print(i)
print(f"Tests: {tests}")
print(f"OK: {ok}")
print(f"KO: {len(lko)}")
print(f"Error: {error}")
print(f"Correct: {(tests - error - len(lko))/(tests - error)*100}%")

# test n moves with 100 numbers
start = time()
moves = []
comb = []
while (42):
    if (len(comb) == 10000): break
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), 100)])
    if (abc in comb): continue
    comb.append(abc)
    out = sub.getoutput(f'{P} {abc} | wc -l | grep -o "[0-9]\+"')
    if (int(out) < 200): print(abc, out, sep="\n"); exit(1)
    try:
        moves.append(int(out))
    except:
        print(abc, out, sep="\n"); exit(1)

with open("nmoves1", "a") as f:
    f.write("\n".join([str(i) for i in moves]))
end = time()
print(f"Number of tests with {len(comb[0].split())} pseudorandom numbers: {len(moves)}")
print(f"Max moves for {len(comb[0].split())} numbers: {max(moves)}")
print(f"Min moves for {len(comb[0].split())} numbers: {min(moves)}")
print(f"Avg moves for {len(comb[0].split())} numbers: {round(sum(moves) / len(moves), 2)}")
print(f"Time: {end - start}s")

start = time()
moves = []
comb = []
while (42):
    if (len(comb) == 1000): break
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), 500)])
    if (abc in comb): continue
    comb.append(abc)
    if (sub.getoutput(f'{P} {abc} | {C} {abc}') != "OK"): print(abc); exit(1)
    out = sub.getoutput(f'{P} {abc} | wc -l | grep -o "[0-9]\+"')
    if (int(out) < 1000): print(abc, out, sep="\n"); exit(1)
    try:
        moves.append(int(out))
    except:
        print(abc, out, sep="\n"); exit(1)

with open("nmoves5", "a") as f:
    f.write("\n".join([str(i) for i in moves]))
end = time()
print(f"Number of tests with {len(comb[0].split())} numbers in input: {len(comb)}")
print(f"Max moves for {len(comb[0].split())} numbers in input: {max(moves)}")
print(f"Min moves for {len(comb[0].split())} numbers in input: {min(moves)}")
print(f"Avg moves for {len(comb[0].split())} numbers in input: {round(sum(moves) / len(moves), 2)}")
print(f"Time: {end - start}s\n")