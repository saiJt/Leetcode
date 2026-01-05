int strStr(char* haystack, char* needle) {
    if (needle[0] == '\0') {
        return 0;
    }
    int n = strlen(needle);
    int i = 1;
    int length = 0;
    int* lps = calloc(n, sizeof(int));


    while (i < n) {
        if (needle[i] == needle[length]) {
            length++;
            lps[i] = length;
            i++;
        }

        else {
            if (length > 0) {
                length = lps[length - 1];
            }

            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    i = 0;
    int j = 0;
    int m = strlen(haystack);

    while (i < m) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;

            if (j == n) {
                return i - j;
            }
        }

        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i += 1;
            }
        }
    }
    return -1;
}
