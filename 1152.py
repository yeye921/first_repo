n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))

arr2 = sorted(arr,reverse=True)

for num in arr2:
    print(num)