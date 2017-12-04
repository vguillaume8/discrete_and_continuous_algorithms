import java.util.HashSet;
import java.util.HashMap;
import java.util.Arrays;

/**
 * Find 2 integers in an array that add up to a give number
 * in linear time
 */
class Sum {
  public static void main(String[] args) {
    int[] array = {3, 0, 2, 5, 2, 100, 7};

    System.out.println(Arrays.toString(array));

    for (int i = 0; i < 20; i++) {
      System.out.println(i + ": " +containsSum(array, i) + " " + containsSum2(array, i));
    }
  }

//------------------------------------------------------------------------------

  /**
   * Time:   O(n)
   * Space : O(n)
   */
  public static boolean containsSum2(int[] array, int sum) {
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

    // Time:  O(n)
    // Space: O(n)
    for (int i = 0; i < array.length; i++) {

      //  Keep track of how many times
      // we have seen a given number
      if (map.containsKey(array[i])) {

        // Increment how many times we have seen it
        map.put(array[i], map.get(array[i]) + 1);

        // First time we have seen it
      } else {
        map.put(array[i], 1);
      }
    }

    // Time: O(n)
    for (int i = 0; i < array.length; i++) {

      // Check that the number is in the map,
      // O(1)
      if (map.containsKey(sum - array[i])) {

        // If we have only seen it once, we cannot count this as valid
        if (array[i] == sum - array[i] && map.get(sum - array[i]) < 2) {
          return false;
        }

        return true;
      }
    }

    return false;
  }

//------------------------------------------------------------------------------

  /**
   * NOTE - Will return true for doubles of every
   * value because duplicates are not counted
   *
   * Time:   O(n)
   * Space : O(n)
   */
  public static boolean containsSum(int[] array, int sum) {
    HashSet<Integer> set = new HashSet<Integer>();

    // Time:  O(n)
    // Space: O(n)
    for (int i = 0; i < array.length; i++) {
      set.add(array[i]);
    }

    // Time: O(n)
    for (int i = 0; i < array.length; i++) {

      // O(1)
      if (set.contains(sum - array[i])) {
        return true;
      }
    }

    return false;
  }
}
