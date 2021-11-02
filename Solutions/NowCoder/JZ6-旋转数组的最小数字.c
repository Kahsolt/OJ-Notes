// 2021/07/02 
// Note: 有BUG，没完全过
 
int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
    if (!rotateArrayLen) return 0;
    
    // 预处理：严格单增化
    int i = 0, j = 0;
    while (i < rotateArrayLen) {
        if (rotateArray[i] != rotateArray[j])
            rotateArray[++j] = rotateArray[i];
        i++;
    }
    rotateArrayLen = j;
    
    // 不断缩小非单增区间
    int left = 0, right = rotateArrayLen - 1, mid = (left + right) >> 1;
    int r = rotateArray[left] <= rotateArray[right] ? rotateArray[left] : rotateArray[right];
    while (left < right) {
        if (rotateArray[left] <= rotateArray[mid])
            left = mid + 1;
        else if (rotateArray[mid] <= rotateArray[right])
            right = mid;
        mid = (left + right) >> 1;
        if (rotateArray[left] < r) r = rotateArray[left];
        if (rotateArray[right] < r) r = rotateArray[right];
    }
    return r;
}