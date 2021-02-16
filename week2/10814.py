import sys
N = int(input())
arr = []
for i in range(N):
    x , y = sys.stdin.readline().split()
    x = int(x)
    arr.append((x, y))

arr = sorted(arr, key = lambda x : x[0])

for i in range(N):
    print(arr[i][0], arr[i][1])
