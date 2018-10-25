# Bogosort: A very effective and efficient sorting algorithm :^)

import random

def isSorted(listOfNums):
  for i in range(len(listOfNums) - 1):
    if listOfNums[i] > listOfNums[i + 1]:
      return False
  return True

def main:
  print("Input a list of numbers (seperated by [enter]s) and terminate input by entering a non-number value")

  listOfNumbers = []
  while True:
    num = input("? ")
    try:
      listOfNumbers.append(float(num))
    except:
      break;

  while not isSorted(listOfNumbers):
    listOfNumbers = random.shuffle(listOfNumbers)
    
if __name__ == "__main__":
  main()
