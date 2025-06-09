import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private static final double CONFIDENCE_95 = 1.96;
    private double[] x; // value of trials

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0) throw new IllegalArgumentException();
        x = new double[trials];
        int all = n * n;
        for (int i = 0; i < x.length; i++) { // trials
            Percolation percolations = new Percolation(n);
            while (!percolations.percolates()) {
                int row = StdRandom.uniformInt(n) + 1, col = StdRandom.uniformInt(n)
                        + 1; // random open
                percolations.open(row, col);
            }
            x[i] = 1.0 * percolations.numberOfOpenSites() / all;
        }
    }

    // sample mean of percolation threshold
    public double mean() {
        return StdStats.mean(x);
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        return StdStats.stddev(x);
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        double m = mean(), stddev = stddev();
        return m - CONFIDENCE_95 * stddev / Math.sqrt(x.length);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        double m = mean(), stddev = stddev();
        return m + CONFIDENCE_95 * stddev / Math.sqrt(x.length);
    }

    // test client (see below)
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        PercolationStats percolationStats = new PercolationStats(n, trials);
        StdOut.println("mean                    = " + percolationStats.mean());
        StdOut.println("stddev                  = " + percolationStats.stddev());
        StdOut.println("95% confidence interval =  [" + percolationStats.confidenceLo() + ", "
                               + percolationStats.confidenceHi() + "]");
    }
}