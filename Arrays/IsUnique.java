// determine if a string has all unique characters.
// implement without  additional data structures

import java.util.Arrays;
import java.util.HashSet;

public class IsUnique {

    public static void main(String[] args) {

         if (isUnique_withoutOtherDataStructures("The quick brown"))

            System.out.println("unique string");
        else
            System.out.println("not unique");
    }

    public static boolean isUnique(String input) {
        HashSet<Character> uniqueCharCount = new HashSet<>();

        for (Character c : input.toCharArray()) {
           // System.out.println("reading " + c + " inside the loop: " + count++ );
            if(Character.isWhitespace(c))continue;

            if (uniqueCharCount.contains(c))
                return false;
            else
                uniqueCharCount.add(c);
        }
        return true;
    }

//alternate method
    public  static boolean isUnique_withoutOtherDataStructures(String input){
        char[] sortedArray = input.toCharArray();
        Arrays.sort(sortedArray);

        for (int i=0;i<sortedArray.length-1;i++
             ) {
            if(Character.isWhitespace(sortedArray[i]))continue;
            if((sortedArray[i]) == sortedArray[i+1])
            return false;
        }
        return true;
    }
}
