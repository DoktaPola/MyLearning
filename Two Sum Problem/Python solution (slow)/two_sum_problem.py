quarters = []

for i, line in enumerate(open("1Mints.txt", "r").read().split("\n")):
    if i == 8000:
        break
    quarters.append(int(line))


def two_sum_problem(arr):
    num = 0
    for num1 in range(len(arr)):
        for num2 in range(num1 + 1, len(arr)):
            if arr[num1] + arr[num2] == 0:
                num += 1
    return num


print(two_sum_problem(quarters))
