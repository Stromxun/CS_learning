import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RandomWord {
    public static void main(String[] args) {
        String word = StdIn.readString();
        int count = 1;
        while (!StdIn.isEmpty()) {
            String s = StdIn.readString();
            count++;
            if (StdRandom.bernoulli(1.0 / count)) {
                word = s;
            }
        }
        StdOut.println(word);
    }
}