from itertools import combinations
from math import comb

n, k = map(int, input().split())

print(comb(n, k))

ans = list(combinations(range(1,n+1),k))

for i in range(len(ans)):
    for j in ans[i]: print(j, end=' ')
    print()
