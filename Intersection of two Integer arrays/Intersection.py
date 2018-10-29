#Written by Kenneth Nero <https://github.com/KennethNero>

# Simple function to create an array of mathcing elements
# between two lists.
def intersection(ls1, ls2):
    result = [v for v in ls1 if v in ls2]
    return result

# Main function that operates on the command line to take
# in and send output. 
def main():
    ls = []
    inp = input("Please enter your first comma seperated list of integers: ")
    inp2 = input("Please enter your second comma seperated list of integers: ")

    result = intersection(inp.replace(' ', '').split(','),
                          inp2.replace(' ','').split(','))
    print("\nIntersection between first and second list:")
    outStr = "["
    for x in result:
        outStr = outStr+str(x)+', '
    print(outStr[0:-2]+']')

if __name__ == "__main__":
    main()
