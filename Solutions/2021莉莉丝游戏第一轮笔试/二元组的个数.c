long long ans(int* array, int arrayLen, int k) {
    long long ret = 0;
    for (int i=0; i<arrayLen-1; i++) {
        if (array[i] < k)
            for (int j=i+1; j<arrayLen; j++) {
                if (array[i] + array[j] <= k)
                    ret++;
            }
    }
    return ret;
}
