import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    // value 0 is represented blocked, value 1 is opened, value 2 is fulled
    private boolean[][] grid; // 2d
    private int numberOfOpen;
    private WeightedQuickUnionUF uf;
    private WeightedQuickUnionUF ufOfFUll;
    private int[] dx = { -1, 0, 0, 1 };
    private int[] dy = { 0, -1, 1, 0 };

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        if (n <= 0) throw new IllegalArgumentException();
        grid = new boolean[n][n];
        ufOfFUll = new WeightedQuickUnionUF(n * n + 1);
        uf = new WeightedQuickUnionUF(n * n + 2);
    }

    private int toIndex(int row, int col) { // start at 1
        return (row - 1) * grid.length + col;
    }

    private boolean isInGird(int row, int col) {
        if (row < 1 || row > grid.length || col < 1 || col > grid.length) {
            return false;
        }
        return true;
    }

    private void connectNeighbor(int row, int col) {
        int newRow, newCol;
        int curr = toIndex(row, col);
        for (int i = 0; i < 4; i++) {
            newRow = row + dx[i];
            newCol = col + dy[i];
            if (isInGird(newRow, newCol) && isOpen(newRow, newCol)) {
                uf.union(curr, toIndex(newRow, newCol));
                ufOfFUll.union(curr, toIndex(newRow, newCol));
            }
        }
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        if (row < 1 || row > grid.length || col < 1 || col > grid.length)
            throw new IllegalArgumentException();
        if (grid[row - 1][col - 1]) { // already open
            return;
        }
        // not open
        numberOfOpen++;
        grid[row - 1][col - 1] = true; // open
        int curr = toIndex(row, col);
        if (row == 1) { // familiar
            uf.union(0, curr);
            ufOfFUll.union(0, curr); // prevent washback
        }
        if (row == grid.length) { // familiar
            uf.union(grid.length * grid.length + 1, curr);
        }
        connectNeighbor(row, col);
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        if (row < 1 || row > grid.length || col < 1 || col > grid.length)
            throw new IllegalArgumentException();
        return grid[row - 1][col - 1];
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        if (row < 1 || row > grid.length || col < 1 || col > grid.length)
            throw new IllegalArgumentException();
        return ufOfFUll.find(0) == ufOfFUll.find(toIndex(row, col));
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return numberOfOpen;
    }

    // does the system percolate?
    public boolean percolates() {
        return uf.find(0) == uf.find(grid.length * grid.length + 1);
    }

    // test client (optional)
    public static void main(String[] args) {
        int n = 6;
        Percolation p = new Percolation(n);
        p.open(1, 1);
        p.open(1, 6);
        p.open(2, 6);
        p.open(3, 6);
        p.open(4, 6);
        p.open(5, 6);
        p.open(5, 5);
        p.open(4, 4);
        p.open(3, 4);
        p.open(2, 4);
        p.open(2, 3);
        p.open(2, 2);
        p.open(2, 1);
        p.open(3, 1);
        p.open(4, 1);
        p.open(5, 1);
        p.open(5, 2);
        p.open(6, 2);
        p.open(5, 4);
        System.out.println(p.percolates());
    }
}