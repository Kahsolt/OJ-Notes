// 2021/07/02 
// Note: 近似于快速排序里的挖坑法，有bug

int* reOrderArray(int* array, int arrayLen, int* returnSize) {
    int E = 0, O = 0;
    while (E < arrayLen && O < arrayLen) {
        while (E < arrayLen && array[E]%2==1) E++;
        while (O < arrayLen && array[O]%2==0) O++;
        if (E < arrayLen && O < arrayLen 
                && array[E]%2==1 && array[O]%2==0) {
            int tmp = array[E];
            array[E] = array[O];
            array[O] = tmp;
        }
    }
    *returnSize = arrayLen;
    return array;
}