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
        for (int j = 0; j < len - 1; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count / 2;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    sort(arr, len);
    for (int i = 0; i < len / 2; ++i) {
        for (int j = len / 2; j >= 0; --j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    if (count > 0) {
        return count - 1;
    }
    else {
        return 0;
    }
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    sort(arr, len);
    int left = 0, right = len - 1;
    for (int i = 0; i < len - 1; ++i) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (value == arr[mid] + arr[i]) {
                count++;
                int newmid = mid - 1;
                while (arr[i] + arr[newmid] == value && left < right) {
                    count++;
                    left++;
                }
                newmid = mid + 1;
                while (arr[i] + arr[newmid] == value && left > right) {
                    count++;
                    right++;
                }
            }
            else if (value > arr[mid] + arr[i]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    if (count > 0) {
        return count / 2;
    }
    else {
        return 0;
    }
}
