using System.Linq;

namespace ArraysOperations
{
    public class ArrrayInteresector
    {
        public int[] IntersectArrays(int[] firstArray, int[] secondArray)
        {
            var setA = firstArray.ToHashSet();
            var setB = secondArray.ToHashSet();

            setA.IntersectWith(setB);
            var intersectArray = setA.ToArray();

            return intersectArray;
        }
    }
} 
