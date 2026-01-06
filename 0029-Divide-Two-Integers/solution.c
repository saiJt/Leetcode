int divide(int dividend, int divisor) {
    
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long divid = llabs((long long)dividend);
    long long divis = llabs((long long)divisor);
    long long tmp;
    long long ans = 0;
    long long multiple;

    while (divid >= divis) {
        tmp = divis;
        multiple = 1;

        while ((tmp << 1) <= divid) {
            tmp <<= 1;
            multiple <<= 1;

        }
        divid -= tmp;
        ans += multiple;
    }

    if (divisor < 0 && dividend < 0) {
        return ans;
    }
    else if (divisor < 0 || dividend < 0) {
        ans = -ans;
    }

    return ans;
}
