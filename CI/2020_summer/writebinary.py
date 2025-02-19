arr = [41, 00, 42, 41, 00, 42]
with open('data3b.txt', 'wb') as f_out:
    for b in arr:
        c = b.to_bytes((1), 'big')
        f_out.write(c)