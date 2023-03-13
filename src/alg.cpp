// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int temp = 0, count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int temp = 0, count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < len; ++i) {
        for (int j = len; j >= len / 2 - 1; --j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int temp = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int left = i, right = len - 1;
        while (right > left) {
            int middle = (left + right) / 2;
            if (arr[i] + arr[middle] == value) {
                count++;
                int newmiddle = middle + 1;
                while (arr[i] + arr[newmiddle] == value && newmiddle < right) {
                    count++;
                    newmiddle++;
                }
                newmiddle = middle - 1;
                while (arr[i] + arr[newmiddle] == value && newmiddle > left) {
                    count++;
                    newmiddle--;
                }
                break;
            }
            if (arr[i] + arr[middle] > value) {
                right = middle;
            }
            else {
                left = middle;
            }
        }
    }
 return count;
}
