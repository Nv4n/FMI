package app;

public class SelectionSort {
    static public void sortArray(Comparable[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int index = i;
            for (int j = i; j < arr.length - 1; j++) {
                int comp = arr[j].compareTo(arr[j + 1]);
                if (comp > 0) index = j;
            }
            Comparable temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}
