import math

n = int(input())

def f(n):
  t = n // 5
  rem = n % 5
  if t == 0:
    return rem * 10 + max(0, rem - 3) * 10
  else:
    prv = t * 70 + 100 * (t * (t - 1) // 2)
    level = t * 2
    bonus = rem * (level + 1) * 10 + max(0, rem - 3)  * 10
    return prv + bonus

l = 0
r = 10**1000
ans = 0
while (l <= r):
  mid = (l + r) >> 1
  fx = f(mid)
  if fx >= n:
    r = mid - 1
    ans = mid
  else:
    l = mid + 1

lv = (ans // 5) * 2 + (1 if ans % 5 >= 3 else 0)
print(lv , f(ans), ' ')
