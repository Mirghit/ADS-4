// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        result++;
      }
    }
  }
  return result;
}
int countPairs2(int *arr, int len, int value) {
  if (len < 2) {
    return 0;
  }
  int result = 0;
  int left = 0;
  int right = len - 1;
  while (right >= 0 && arr[right] > value) {
    right--;
  }
  while (left < right && arr[left] + arr[right] < value) {
    left++;
  }
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value){
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        result += n * (n - 1) / 2;
        break;
      }
      int leftEl = arr[left];
      int leftDoubles = 0;
      while (arr[left] == leftEl) {
        leftDoubles++;
        left++;
      }
      int rightEl = arr[right];
      int rightDoubles = 0;
      while (arr[right] == rightEl) {
        rightDoubles++;
        right--;
      }
      result += leftDoubles * rightDoubles;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return result;
}
int countPairs3(int *arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len - 1; i++) {
    int found = value - arr[i];
    int start = i + 1;
    int end = len - 1;
    int fp = -1;
    int lp = -1;
    int low = start;
    int high = end;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      if (arr[middle] == found) {
        fp = middle;
        high = middle - 1;
      } else if (arr[middle] < found) {
        low = middle + 1;
      } else {
        high = middle - 1;
      }
    }
    if (fp == -1) continue;
    low = fp;
    high = end;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      if (arr[middle] == found) {
        lp = middle;
        low = middle + 1;
      } else if (arr[middle] < found) {
        low = middle + 1;
      } else {
        high = middle - 1;
      }
    }
    result += (lp - fp + 1);
  }
  return result;
}
