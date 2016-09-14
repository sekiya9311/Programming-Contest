l1, r1, l2, r2, k = map(int, raw_input().split())
ans = 0
r = min(r1, r2)
l = max(l1, l2)
ans = r - l + 1
if l <= k and k <= r:
    ans -= 1
if ans < 0:
    ans = 0
print ans
