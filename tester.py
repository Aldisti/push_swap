# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 15:55:16 by adi-stef          #+#    #+#              #
#    Updated: 2023/02/14 13:05:03 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
from random import sample
import subprocess as sub

MAX = 2147483647
MIN = -2147483648
P = "./push_swap"
C = "./checker_MAC"
tests = 0
error = 0
ok = 0
ko = 0
lko = []

# test 2
if (sub.getoutput(f'{P} "{MAX} {MIN} | {C} {MAX} {MIN}') == "KO"): ko += 1
if (sub.getoutput(f'{P} {MIN} {MAX} | {C} {MIN} {MAX}') == "KO"): ko += 1
tests += 2

# test 3
for a in range(3):
    for b in range(3):
        for c in range(3):
            cmd = str(f"{P} {a} {b} {c} | {C} {a} {b} {c}")
            tests += 1
            out = sub.getoutput(cmd)
            if (out == "KO"): ko += 1; lko.append(str(a) + str(b) + str(c))
            elif (out == "Error"): error += 1
            elif (out == "OK"): ok += 1

# test 5
for _ in range(100):
    tests += 1
    abc = ' '.join([str(i) for i in sample(range(MIN, MAX), 5)])
    out = sub.getoutput(f'{P} {abc} | {C} {abc}')
    if (out == "KO"): ko += 1; lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

# test 100
for _ in range(100):
    tests += 1
    abc = ' '.join([str(i) for i in sample(range(MIN, MAX), 100)])
    out = sub.getoutput(f"{P} {abc} | {C} {abc}")
    if (out == "KO"): ko += 1; lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

# test 500
for _ in range(100):
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), 500)])
    out = sub.getoutput(f'{P} {abc} | {C} {abc}')
    if (out == "KO"): ko += 1; lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

# test from 0 to 500
for i in range(0, 500):
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), i)])
    out = sub.getoutput(f'{P} {abc} | {C} {abc}')
    if (out == "KO"): ko += 1; lko.append(abc)
    elif (out == "Error"): error += 1
    elif (out == "OK"): ok += 1

print(f"OK: {ok}")
print(f"KO: {ko}")
print(lko)
print(f"Error: {error}")
print(f"Correct: {(tests - error)/(tests - error)*100}%")

# test n moves with 100 numbers
moves = []
for _ in range(100):
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), 100)])
    out = sub.getoutput(f'./push_swap {abc} | wc -l | grep -o "[0-9]\+"')
    moves.append(int(out))

#print(moves)
print(f"Tests: {len(moves)}")
print(f"Max moves for 100 numbers: {max(moves)}")
print(f"Avg moves for 100 numbers: {round(sum(moves) / len(moves), 2)}")

moves = []
for _ in range(100):
    abc = " ".join([str(i) for i in sample(range(MIN, MAX), 500)])
    out = sub.getoutput(f'./push_swap {abc} | wc -l | grep -o "[0-9]\+"')
    moves.append(int(out))

print(f"Tests: {len(moves)}")
print(f"Max moves for 500 numbers: {max(moves)}")
print(f"Avg moves for 500 numbers: {round(sum(moves) / len(moves), 2)}")
