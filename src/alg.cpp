// Copyright 2021 NNTU-CS
void sort(int *arr, int len) {
    int temp = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    sort(arr, len);
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len - 1; ++j) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    sort(arr, len);
    for (int i = 0; i < len - 1; ++i) {
        for (int j = len - 1; j > i; --j) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    sort(arr, len);
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int l = i, r = len;
        while (1 < r - l) {
            int center = (l + r) / 2;
            if (arr[i] + arr[center] == value) {
                count += 1;
                int j = center + 1;
                while (arr[i] + arr[j] == value && j < r) {
                    count += 1;
                    j++;
                }
                j = center - 1;
                while (arr[i] + arr[j] == value && j > l) {
                    count += 1;
                    j--;
                }
                break;
            }
            if (arr[i] + arr[center] > value) {
                r = center;
            } else {
                l = center;
            }
        }
    }
    return count;
}
