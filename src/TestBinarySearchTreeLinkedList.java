import helper.Arrays;
import helper.Helper;
import structures.BinarySearchTreeLinkedList;

public class TestBinarySearchTreeLinkedList {

	public static void main(String[] args) throws Exception {
		int numPerms = 10;

		System.out.println("n\t" +
				   "E(n)\t" +
		           "E(n)/n*log2n\t" +
				   "E(n)/n^2\t");
		System.out.println("------------------------------------------------");

		for (int n = 10; n <= 200; n+=10) {
			int[] array = Arrays.randomArray(n);
			BinarySearchTreeLinkedList bst;
			double En;
			int sum = 0;

			//Get a given # of random permutation of the array
			for (int i = 0; i < numPerms; i++) {
				bst = new BinarySearchTreeLinkedList(Arrays.permutation(array));
				sum += bst.numComparisons;
			}

			En = (double) sum / numPerms;


			//Compare results
			System.out.format("%d\t%.1f\t%.3f\t\t%.3f\n",
							n,
							En,
							En/(n*Helper.log(2, n)),
							En/(n*n));
		}
	}

}
