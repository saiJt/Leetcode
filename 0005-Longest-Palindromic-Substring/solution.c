char* longestPalindrome(char* s) {

    int n = strlen(s);
    int maxlen = 0;      // length of longest palindrome
    int start = 0;       // starting index of longest palindrome

    for (int i = 0; i < n; i++) {

        // Odd-length palindrome (center at i)
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > maxlen) {
            maxlen = right - left - 1;
            start = left + 1;
        }

        // Even-length palindrome (center between i and i+1)
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > maxlen) {
            maxlen = right - left - 1;
            start = left + 1;
        }
    }

    // Build result substring
    char* result = malloc(maxlen + 1);
    for (int i = 0; i < maxlen; i++) {
        result[i] = s[start + i];
    }
    result[maxlen] = '\0';

    return result; // caller must free
}
