package HW.HW01;

public class Exercise_1b {

    public static void drawTriangle(int N){
        int row = 0;
        while (row < N) {
            int col = 0;
            while (col <= row) {
                System.out.print('*');
                col = col + 1;
            }
            System.out.println();
            row = row + 1;
        }
    }
    public static void main(String[] args) {
        drawTriangle(10); 
    }
}