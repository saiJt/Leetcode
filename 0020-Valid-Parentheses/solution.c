bool isValid(char* s) {
    if (s == NULL) {
        return false;
    }    

    int n = strlen(s);
    char stack[n];
    int top = -1;

    int i =0;

    while (s[i] != '\0') {
        if (s[i] == '[') {
            top++;
            stack[top] = ']';
        }
        else if (s[i] == '{') {
            top++;
            stack[top] = '}';
        }

        else if (s[i] == '(') {
            top++;
            stack[top] = ')';
        }

        else if(s[i] == ']' || s[i] == '}' || s[i] == ')') {
            if (top == -1) {
                return false;
            }
            else if (stack[top] != s[i]) {
                return false;
            }
            top--;
        }
        i++;
    }

    if (top != -1) {
        return false;
    }
    return true;
}
