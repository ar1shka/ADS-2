// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int ff = 0;
for (int i = 0; i < len-1; i++) {
for (int j = i+1; j <= len; j++) {
if (arr[i] + arr[j] == value) ff=ff+1;
}
}
return ff;
}
int countPairs2(int *arr, int len, int value) {
int ff = 0, l = 0;
for (int i = 0; i < len-1; i++) {
if (arr[i] >= value) {
l = i;
break;
}
}
for (int i = l; i >= 0; i--) {
for (int j = 0; j < i; j++) {
if (arr[i] + arr[j] == value)
ff++;
}
}
return ff;
}

int countPairs3(int *arr, int len, int value) {
int count = 0, left = 0, right = len - 1;
int ff = 0, l = 0;
for (int i = 0; i < len-1; i++) {
if (arr[i] >= value) {
l = i;
break;
}
}
for (int i = 0; i < l; i++) {
left = i + 1, right = l;
while (left < right) {
int m = (left + right) / 2;
if (arr[m] < (value - arr[i]))
left = m + 1;
else
right = m;
}
while (arr[left] == (value - arr[i])) {
ff++;
left++;
}
}
return ff;
}
