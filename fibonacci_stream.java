
import java.util.stream.Collectors;
import java.util.stream.Stream;

class StreamFib {

    public static void main(String args[]) {
        int n = 42;
        System.out.println(Stream.iterate(new int[]{0, 1}, i -> new int[]{i[1], i[0] + i[1]})
                .limit(n + 1)
                .map(i -> i[0])
                .collect(Collectors.toList())
                .get(n));
    }
}

