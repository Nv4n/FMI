package lab3.b.Zad2;

public class SortUtilsTest {
    public static void main(String[] args) {
        int[] arr1 = new int[5];
        SortUtils.init(arr1);
        SortUtils.sortBbl(arr1);
        int[] arr2 = new int[3];
        SortUtils.init(arr2);
        SortUtils.sortBbl(arr2);

        SortUtils.print(arr1);
        SortUtils.print(arr2);
        int[] arr3 = SortUtils.mergeSort(arr1, arr2);

        SortUtils.print(arr3);
    }
}
