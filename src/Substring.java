class Substring {
  public static void main(String[] args) {

    String string = "jadariobadashwashere";
    System.out.println(containsSubstring(string, "dash"));
  }

  public static boolean containsSubstring(String s, String ss) {
    char[] string = s.toCharArray();
    char[] substring = ss.toCharArray();
    int offset = -1;
    boolean contains = false;
    int j;

    // Edge case
    if (substring.length == 0) {
      return false;
    }

    // Edge case
    if (substring.length > string.length) {
      return false;
    }

    for (int i = 0; i < string.length; i++) {
      if (contains == true) {
        break;
      }

      if (string[i] == substring[0]) {
        offset = i;
        j = 0;

        while (j < substring.length) {
          if (offset + j >= string.length) {
            break;
          }

          if (string[offset + j] != substring[j]) {
            break;
          }

          // Keep going
          j++;
          i++;

          if (j == substring.length) {
            contains = true;
          }
        }
      }
    }

    return contains;
  }
}
