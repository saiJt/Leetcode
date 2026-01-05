class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
      if needle == "":
        return 0
      
      i = 1 # Start with 1 because lps[0] is always 0 by definition,
      length = 0
      lps = [0] * len(needle)

      while i < len(needle):
        if needle[i] == needle[length]: # The current character matches the character following the
                                        # previously matched prefix - the prefix-suffix match can be extended by one character.
          length += 1   # increase the length of the current longest prefix/suffix
          lps[i] = length #store the length of the longest proper prefix/suffix for the substring needle.
          i += 1

        else:
          if length > 0:     # A mismatch occurred, but there is still a shorter prefix that might match.
                             # Fall back to the previous longest prefix length.
            length = lps[length-1]      
                      # Reduce the prefix length to the longest proper prefix of the previously matched prefix.
                      # The index i is not moved, so the comparison is retried with the shortened prefix.
            
          else:
            lps[i] = length;
            i += 1
