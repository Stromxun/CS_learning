void rotate(char matrix[10][10]) {
    int len = 10;
    for (int i = 0; i < (len + 1) / 2; i++) {
        for (int j = i; j < len - i - 1; j++) {
        // rotate
        char tmp = matrix[j][i]; // lt                                                    
        matrix[j][i] = matrix[len - i - 1][j]; // ld                                      
        matrix[len - i - 1][j] = matrix[len - j - 1][len - i - 1]; // rd     
        matrix[len - j - 1][len - i - 1] = matrix[i][len - j - 1]; // rt                  
        matrix[i][len - j - 1] = tmp; // finish	
        }
    }
}
