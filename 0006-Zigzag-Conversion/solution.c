char* convert(char* s, int numRows) {
    int len = strlen(s);

    // Allocate an array of pointers, one string buffer per row
    char **rows = malloc(numRows * sizeof(char *));
    // Track current length of each row string
    int* rowlen = calloc(numRows, sizeof(int));

    // Allocate enough space for each row
    for (int i = 0; i < numRows; i++) {
        rows[i] = malloc(len + 1);
    }

    // zigzag is meaningless with only one row
    if (numRows == 1) return s;

    int turn = 0; // 0 = moving down, 1 = moving up
    int row = 0;  // current row index

    // Distribute characters into rows following zigzag movement
    for (int i = 0; i < len; i++) {
        rows[row][rowlen[row]] = s[i]; // append character to current row
        rowlen[row]++;

        // Move to next row based on current direction
        if (turn == 0) row++;
        else row--;

        // Change direction at top or bottom row
        if (row == numRows - 1) turn = 1;
        if (row == 0) turn = 0;
    }

    // Null terminate each row string
    for (int i = 0; i < numRows; i++) {
        rows[i][rowlen[i]] = '\0';
    }

    // Build final result by concatenating rows top to bottom
    char *result = malloc(len + 1);
    int pos = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowlen[i]; j++) {
            result[pos++] = rows[i][j];
        }
    }
    result[pos] = '\0';

    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }
    free(rows);
    free(rowlen);

    return result;
}
