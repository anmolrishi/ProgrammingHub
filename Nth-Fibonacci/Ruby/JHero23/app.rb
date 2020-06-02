# Declare a method/function that creates the fibonacci sequence
def fibonacci(num)
    if num < 0
        return "Negative number not implemented yet"
    elsif num <= 1
        return num
    else
        return fibonacci(num - 1) + fibonacci(num - 2)
    end
end


begin
    # Prompt the user
    print "Enter a number: "
    input = gets.chomp.to_i

    p "Your number is #{input}"

    # Generate the Fibonacci sequence
    num_list = []

    begin
        num_list.push(fibonacci(input))
        input -= 1
    end while input.to_i >= 0

    p "Your fibonacci numbers are #{num_list}"

    print "\nWant to try again? "
    ans = gets.chomp.downcase
end while ans == 'y' || ans == "yes"
