int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int area = 0;
        if (height[left] <= height[right]) {
            area = height[left] * (right-left);
            
        }
        else {
            area = height[right] * (right - left);
        }
        if (max_area < area) {
            max_area = area;
        }
        if (height[left] < height[right]) {
            left++;
        }
        else {
            right--;
        }
    }
    return max_area;
}
