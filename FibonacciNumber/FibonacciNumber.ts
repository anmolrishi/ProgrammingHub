class FibonacciNumbers {
    public Generate(count: number) {
        if (count < 2) {
            return count;
        } else {
           return this.Generate(count-1) + this.Generate(count-2);
        }
    }
}