import sys
input = sys.stdin.readline

N, M = map(int, input().split())

nolisten = [input().strip() for _ in range(N)]
noseen = [input().strip() for _ in range(M)]
nono = []

nolisten.sort()
noseen.sort()

def find_person(namelist):
    for name in namelist:
        start, end = 0, len(noseen) - 1
    
        while start <= end:
            mid = (start + end) // 2
            if name == noseen[mid]:
                nono.append(name)
                break
            elif name < noseen[mid]:
                end = mid - 1
            else:
                start = mid + 1
                
        if start > end:
            continue
    
    print(len(nono))
    for name in nono:
        print(name)

find_person(nolisten)