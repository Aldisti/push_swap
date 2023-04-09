# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 21:35:54 by adi-stef          #+#    #+#              #
#    Updated: 2023/03/25 22:02:41 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from random import sample

arr = [int(i) for i in sample(range(0, 500), 500)]
moves = 0
while (arr != sorted(arr)):
    i = 0
    while (i < len(arr) - 1 and arr != sorted(arr)):
        if (arr[i] > arr[i + 1]):
            arr[i], arr[i + 1] = arr[i + 1], arr[i]
        i += 1
        moves += 1
    while (i > 0 and arr != sorted(arr)):
        if (arr[i - 1] > arr[i]):
            arr[i - 1], arr[i] = arr[i], arr[i - 1]
        i -= 1
        moves += 1

print(arr)
print(moves)
print(500*500)