def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

n, m = map(int,input().split())
gcd_v = gcd(max(n,m),min(n,m))
lcm_v = (n * m) // gcd_v
print(gcd_v)
print(lcm_v)
