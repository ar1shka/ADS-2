// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
int ff = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j <= len; j++) {
if (arr[i] + arr[j] == value) ff = ff + 1;
}
}
return ff;
}
int countPairs2(int* arr, int len, int value)
{
int ff = 0, l = 0;
for (int i = 0; i < len; i++) {
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
int countPairs3(int* arr, int len, int value) {
int ff = 0;
int r = len - 1;
int l = 0;
while (l < r - 1) {
int m = (l + r) / 2;
if (arr[m] <= value)
l = m;
else
r = m;
}
len = r - 1;
for (int i = 0; i < len; i++) {
l = i + 1, r = len - 1;
int k = 0;
while (l < r) {
int m = (l + r) / 2;
if (arr[m] < (value - arr[i]))
l = m + 1;
else
r = m;
}
while (arr[l] == (value - arr[i])) {
k++;
l++;
}
ff = ff+k;
}
return ff;
}
