import random
import time

# array = random.sample(range(-5000, 5000), 5000)

# array = [2, 4, 1, 3, 5]
array = [10, -2, 5, 3, 4, 9]
array2 = array.copy()


def merge(arr, low, mid, high, arr2):
    second_half = mid
    for i in range(low, high + 1):
        arr2[i] = arr[i]
    for i in range(low, high + 1):
        if low >= mid:
            arr[i] = arr2[second_half]
            second_half += 1
        elif second_half > high:
            arr[i] = arr2[low]
            low += 1
        elif arr2[low] > arr2[second_half]:
            arr[i] = arr2[second_half]
            second_half += 1
        elif arr2[low] < arr2[second_half]:
            arr[i] = arr2[low]
            low += 1


def sort(arr, low, high, arr2):
    mid = low + (high - low) // 2
    if low < high:
        sort(arr, low, mid, arr2)
        sort(arr, mid + 1, high, arr2)
        merge(arr, low, mid + 1, high, arr2)
        return arr
    return arr


print(sort(array, 0, len(array) - 1, array2))

# start = time.time()
# sort(array, 0, len(array) - 1, array2)
# end = time.time()
# elapsed = end - start
#
# if sorted(array) == array:
#     print("Sorted")
# else:
#     print("Not sorted")
#
# print("MERGE SORT time elapsed:", elapsed, "sec.")
