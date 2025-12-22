int lengthOfLongestSubstring(char* s) {
    // Frequency array for ASCII characters
    int seen[256] = {0};

    int left = 0;
    int right = 0;
    int n = 0;
    int maxlen = 0;

    // Compute string length manually
    while (s[n] != '\0') {
        n++;
    }

    // Sliding window
    for (right = 0; right < n; right++) {
        // Add current character to the window
        seen[(unsigned char)s[right]]++;

        // If duplicate exists, shrink the window from the left
        while (seen[(unsigned char)s[right]] > 1) {
            seen[(unsigned char)s[left]]--;
            left++;
        }

        // Window is valid (no duplicates), update maximum length
        int curlen = right - left + 1;
        if (curlen > maxlen) {
            maxlen = curlen;
        }
    }

    return maxlen;
}
