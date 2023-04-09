# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    plot.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 10:08:27 by adi-stef          #+#    #+#              #
#    Updated: 2023/03/26 10:08:30 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import numpy as np

maxlis = []
maxnolis = []
avglis = []
avgnolis = []
x = []
for i in range(6, 501):
    x.append(i)
    with open(f"Moves/moves{i}.txt", "r") as f:
        nums = (f.readlines())
    nums = [int(i.replace('\n', '')) for i in nums]
    avglis.append(int(sum(nums)/len(nums)))
    maxlis.append(max(nums))
    with open(f"Moves/nolis{i}.txt", "r") as f:
        nums = (f.readlines())
    nums = [int(i.replace('\n', '')) for i in nums]
    avgnolis.append(int(sum(nums)/len(nums)))
    maxnolis.append(max(nums))

maxlis = np.array(maxlis)
maxnolis = np.array(maxnolis)
avglis = np.array(avglis)
avgnolis = np.array(avgnolis)
xpoints = np.array(x)

# print(ypoints)
# print(xpoints)

plt.subplot(2, 1, 1)
plt.plot(xpoints, maxlis, linestyle = 'solid', c = 'b')
plt.plot(xpoints, maxnolis, linestyle = 'solid', c = 'r')

plt.ylabel("Max moves")

plt.legend(["lis", "nolis"], loc=0, frameon=True)

plt.subplot(2, 1, 2)
plt.plot(xpoints, avglis, c = '#33FFFC')
plt.plot(xpoints, avgnolis, c = '#FF6633')

plt.ylabel("Avg moves")
plt.xlabel("Input numbers")

plt.legend(["avglis", "avgnolis"], loc=0, frameon=True)

plt.show()