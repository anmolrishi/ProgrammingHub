// fibonacci finding method

double fib(int n) {
  
  if(n < 1){
    println("There is no fibonacci number before the first");
    return 0;
  }
  else{
  
    double current = 1;
    double last = 0;
  
    // switch case for specific cases of the fibonacci sequence
    switch (n) {
    case 1: 
      println(0); 
      return 0;
    case 2: 
      println(0); 
      println(1); 
      return 1;
    default: 
      println(0); 
      println(1);
    }
    // iterates the fibonacci sequence adding the previous number to the current number then assigning the new value as the current value and moving the middle of the 3 values to the new last slot
    for (int i = 0; i < n - 2; i++) { // int used to keep track of the count as doubles will overflow to negative before the int values overflow (the double passes over to infinity at i == 1477)
      double temp = 0;
      temp = current;
      current = current + last;
      last = temp;
      println(current);
    }
    // returns the nth fibonacci number
    return current;
  }
}


//------------------------------------------------------------


// fibonacci finding method with a nicer console display

double fibSci(int n) {
  
  if(n < 1){
    println("There is no fibonacci number before the first");
    return 0;
  }
  else{
  
    double current = 1;
    double last = 0;
  
    // switch case for specific cases of the fibonacci sequence
    switch (n) {
    case 1: 
      println(0); 
      return 0;
    case 2: 
      println(0); 
      println(1); 
      return 1;
    default: 
      println(0); 
      println(1);
    }
    // iterates the fibonacci sequence adding the previous number to the current number then assigning the new value as the current value and moving the middle of the 3 values to the new last slot
    for (int i = 0; i < n - 2; i++) { // int used to keep track of the count as doubles will overflow to negative before the int values overflow (the double passes over to infinity at i == 1477)
      double temp = 0;
      temp = current;
      current = current + last;
      last = temp;
      // Code block for printing the answer in a scientific way when outputting to console
      { 
        String answer = Double.toString(current);
        String multiplier = "";
        String exponent = "";
        short count = 0;
  
        // finds the E character in the double and takes note of its position
        for (short eCount = 0; eCount < answer.length(); eCount++) {
          if (answer.charAt(eCount) == 'E') {
            count = eCount;
          }
        }
        
        
        if (count > 0) {
          
          // assigns the exponent to a string to be displayed
          for (int expCount = 1; expCount < answer.length() - count; expCount++) {
            exponent = exponent + answer.charAt(count + expCount);
          }
          
          // assigns the multiplier to a string to be displayed
          for (int mulCount = 0; mulCount < 5; mulCount++) {
            multiplier = multiplier + answer.charAt(mulCount);
          }
          
          println(multiplier + "x10^" + exponent);
        } 
        else {
          println(answer);
        }
      }
    }
    // returns the nth fibonacci number
    return current;
  }
}