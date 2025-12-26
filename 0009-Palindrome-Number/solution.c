bool isPalindrome(int x) {

    if (x % 10 == 0 && x != 0) return false;
    if (x < 0) return false;

    int reverse = 0;

    while (x > reverse) {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    
    if (reverse > x) {
        reverse /= 10;
    }

    return (reverse == x);
}
