char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return ("");
    }
    
    char* first = strs[0];

    for (int i = 0; first[i] != '\0'; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][j] == '\0' || strs[j][i] != first[i]) {
                first[i] = '\0';
                return first;
            }
        }
    }
    return first;
}
