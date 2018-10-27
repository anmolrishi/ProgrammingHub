# Function to Reverse each word of string
def reverse(s): 
  string = s.split(" ")# split string into words
  # create new list and apply list comprehension
  new = [i[::-1] for i in string]
  # join to form new string
  newstring = " ".join(new)
  return newstring
# Driver's Code 
s = input("Enter a string:)
print(reverse(s))
