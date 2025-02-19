# Can also use 'factor' linux command
import primefac

def get_decomposition(n):
    return list(primefac.primefac(n))


def main():
    n = 3858843578360632069557337
    e = 551263368336670859257571
    pq = get_decomposition(n)
    # print(pq)

    # Using p and q we can compute d, then decrypt the file
    p = pq[0]
    q = pq[1]
    d = ((p - 1) * (q - 1) + 1) // e
    res = []
    with open('data5.txt', 'r') as f:
        arr = f.read().split()
    for c in arr:
        c= int(c)
        m = pow(c, d, n)
        # m = 2 ** 24 * b0 + 2 ** 16 * b1 + 2 ** 8 * b2 + b3
        b = [0, 0, 0, 0]
        for i in range(0, 4):
            b[3 - i] = m % 256
            m -= b[3 - i]
            m = m // 256
        for i in range(0, 4):
            res.append(b[i])
    with open('data5ans.txt', 'wb') as f:
        for num in res:
            f.write(bytes([num]))

if __name__ == "__main__":
    main()