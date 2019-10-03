# JHero23 - Fibonacci Function
# FIBONACCI FUNCTION
def fibonacci(num)
    if (num == 1 || num == 0)
        return num
    else
        return fibonacci(num - 1) + fibonacci(num - 2)
    end
end

begin
    print "Enter a number: "
    input = gets.chomp.to_i
    if (input <= 0)
        p "input must be greater than 0"
    else
            
        p "Number entered: #{input}"
        num_list = []
        begin
            num_list.append(fibonacci(input))
            input = input - 1
        end while input != 0
        p "Fibonacci result: "
        p num_list    
    end

    print "Try again? "
    ans = gets.chomp.downcase!
end while ans == 'y' || ans == "yes"
