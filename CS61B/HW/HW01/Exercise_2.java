package HW.HW01;

public class Exercise_2 {
   public static int max(int[] m){
        if (m.length == 0){
           return -1; // The array m not have element
        }
        int maxm = m[0], len = m.length, beg = 1;
        while (beg < len){
            if (maxm < m[beg]){
                maxm = m[beg];
            }
            beg += 1;
        }
        return maxm;
   }
   
   public static void main(String[] args) {
        int[] numbers = new int[]{9, 2, 15, 2, 22, 10, 6};
        System.err.println(max(numbers));
   }
}
