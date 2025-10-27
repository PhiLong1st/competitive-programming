import sys 
from math import comb

def solve():
    data = list(map(int, sys.stdin.read().strip().split())) 
    it = iter(data)
    
    n = next(it); m = next(it); k = next(it)

    a = [next(it) for _ in range(m)]
    s = sum(a)

    if s < n:
        print(-1)
        return

    total_ways = comb(s - 1, n - 1)
    ways = total_ways - comb(s - a[k - 1], n - 1)
    print(f"{ways / total_ways:.6f}")

if __name__ == "__main__":
    solve()
