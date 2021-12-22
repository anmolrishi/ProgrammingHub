#!/usr/bin/env python3

def zeros_to_tail(arr):
    zeroes = 0
    end_of_nonzero_numbers = 0
    for num in arr:
        if num == 0:
            zeroes += 1
        else:
            arr[end_of_nonzero_numbers] = num
            end_of_nonzero_numbers += 1
    for idx in range(end_of_nonzero_numbers, len(arr)):
        arr[idx] = 0
    return arr



test = [1, 0, 2, 0, 3, 0, 0, 0, 4, 5, 0, 69, 0]

print(zeros_to_tail(test))

