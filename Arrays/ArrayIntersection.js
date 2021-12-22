var ArraysIntersection = (function () {

    function ArraysIntersection() {
    }

    ArraysIntersection.prototype.Intersect = function (firstArray, secondArray) {

        var intersectedArray = [];
        var dictionary = {};

        for (var _i = 0, firstArray_1 = firstArray; _i < firstArray_1.length; _i++) {
            var element = firstArray_1[_i];
            if (!(element in dictionary)) {
                dictionary[element] = 1;
            }
        }

        for (var _a = 0, secondArray_1 = secondArray; _a < secondArray_1.length; _a++) {
            var element = secondArray_1[_a];
            if (element in dictionary && intersectedArray.indexOf(element) === -1) {
                intersectedArray.push(element);
            }
        }

        return intersectedArray;
    };

    return ArraysIntersection;
}());
