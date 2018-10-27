var FibonacciNumber = (function () {
    function FibonacciNumber() {
    }

    FibonacciNumber.prototype.Generate = function (count) {
        if (count < 2) {
            return count;
        }
        else {
            return this.Generate(count - 1) + this.Generate(count - 2);
        }
    };

    return FibonacciNumber;
}());
