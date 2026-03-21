int maxWater(int* height, int n) {
    int left = 0, right = n - 1, max = 0;
    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int water = h * (right - left);
        if (water > max) max = water;
        if (height[left] < height[right]) left++;
        else right--;
    }
    return max;
}


1. Initialize two pointers:
   - left = 0 (start of array)
   - right = n-1 (end of array)

2. Calculate area:
   - Width = right - left
   - Height = min(height[left], height[right])
   - Area = width * height

3. Update maximum area if current area is larger.

4. Move pointers:
   - If height[left] < height[right], increment left (to try for a taller line).
   - Else, decrement right.

5. Repeat until left < right.

6. Return the maximum area found.
