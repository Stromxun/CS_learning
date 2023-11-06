package HW.HW01;

public class Exercise_3 {
    /** Returns the maximum value from m using a for loop. */
    public static int forMax(int[] m) {
        if (m.length == 0){
           return -1; // The array m not have element
        }
        int maxm = m[0], len = m.length;
        for (int i = 1; i < len; i++){
            if (maxm < m[i]){
                maxm = m[i];
            }
        }
        return maxm;
    }
    public static void main(String[] args) {
       int[] numbers = new int[]{9, 2, 15, 2, 22, 10, 6};      
       System.err.println(forMax(numbers));
    }
}
