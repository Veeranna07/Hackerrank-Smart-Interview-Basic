import math
import os
import random
import re
import sys

def migratoryBirds(arr):
    buckets = [0 for _ in range(6)]
    for b in arr:
        buckets[b] += 1
    m = max(buckets)
    for i in range(1, 6):
        if buckets[i] == m:
            return i

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
