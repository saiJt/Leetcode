/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs (char** result, int* returnSize, char* current, int open, 
int close, int n, int idx) {
    if (idx == 2 * n) {
        char *s = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(s,current);
        result[*returnSize] = s;
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[idx] = '(';
        dfs(result, returnSize, current, open+1, close, n, idx + 1);
        
    }

    if (open > close) {
        current[idx] = ')';
        dfs(result, returnSize, current, open, close+1, n, idx+1);
    }
}


char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;

    char** result = (char **)malloc(sizeof(char*) * 1500);
    char* current = (char *)malloc(sizeof(char) * (2 * n + 1));
    current[2 * n] = '\0';

    dfs (result, returnSize, current, 0, 0, n, 0); 

    free(current);
    return result;
}
