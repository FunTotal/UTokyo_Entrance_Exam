def main():
    lines = []
    pxls = []
    with open('./CI/2019_summer/image1.txt', 'r') as f:
        lines = f.readlines()

    for l in lines:
        ns = l.strip().split(' ')
        for i in range(0,len(ns),3):
            pxls.append((ns[i],ns[i+1],ns[i+2]))

    print(f"No. of pixels: {len(pxls)}")

if __name__ == "__main__":
    main()