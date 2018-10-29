def zeros_to_tail(arr)
    zereos=0
    end_of_nonzero_numbers=0
    arr.each do |item|
        if item==0
            zereos+=1
        else
            arr[end_of_nonzero_numbers] = item
            end_of_nonzero_numbers += 1
        end
    end
    
    while end_of_nonzero_numbers<arr.length do
        arr[end_of_nonzero_numbers]=0
        end_of_nonzero_numbers+=1
    end
return arr
end

test_array = [1, 0, 2, 0, 0, 0, 0, 0, 4, 5, 0, 69, 0]

puts zeros_to_tail(test_array)