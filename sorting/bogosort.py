import random
import time

# Determine if the data is sorted
def is_sorted(data):
    for i in range(len(data) - 1):
        if (data[i] > data[i + 1]):
            return False
    return True

# Perform the bogosort, print some metrics, and return the sorted data
def sort(data):
    start_time = time.time()
    iterations = 1
    while not is_sorted(data):
        iterations += 1
        random.shuffle(data)

    duration = time.time() - start_time

    print("Iterations: " + str(iterations))
    print("  Duration: " + str(duration) + " s")
    return data
