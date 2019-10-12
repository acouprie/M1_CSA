public class Loop2 {
    final int MATRIX_SIZE = 3;
    public static void main(String[] args) {
        int[][] matrix = new int[MATRIX_SIZE][MATRIX_SIZE];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = i + j;
            }
        }
        for (int[] a : matrix) {
            for (int i : a) {
                System.out.print(i + "\t");
            }
            System.out.println("\n");
        }
        /* for (int i = 0; i < MATRIX_SIZE + 1; i++) {
            for (int j = 0; j < MATRIX_SIZE + 1; j++) {

            }
        }*/
    }
}
