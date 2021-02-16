def add_digit(i, hap):
    hap += i%10
    i = i//10
    if i > 0 :
        return add_digit(i, hap)
    else:
        return hap
def bunhae(N):
    for i in range(1, N):
        hap=0
        hap=add_digit(i, hap) + i
        if hap == N:
            return i
        else:
            return 0
N = int(input())
print(bunhae(N))
