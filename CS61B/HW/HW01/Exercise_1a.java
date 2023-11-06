package HW.HW01;

/**
 * Drawing_a_Triangle
 */
public class Exercise_1a {

    public static void main(String[] args) {
        int row = 0;
        int SIZE = 5;
        while (row < SIZE) {
            int col = 0;
            while (col <= row) {
                System.out.print('*');
                col = col + 1;
            }
            System.out.println();
            row = row + 1;
        }
    }
}