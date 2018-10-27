class ArraysIntersection {
    public Intersect(firstArray: number[], secondArray: number[]) {

        let intersectedArray: number[] = [];
        let dictionary: {} = {};

        for (let element of firstArray) {
          if (!(element in dictionary)) {
            dictionary[element] = 1;
          }
        }

        for (let element of secondArray) {
          if (element in dictionary && intersectedArray.indexOf(element) === -1) {
            intersectedArray.push(element);
          }
        }

        return intersectedArray;
    }
}