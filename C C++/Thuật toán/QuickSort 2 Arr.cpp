
int partion(int a[], int b[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j=l; j<r; ++j) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
            swap(b[i], b[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    swap(b[i], b[r]);
    return i;
}

void QuickSort(int a[], int b[], int l, int r) {
    if (l >= r) return;
    int p = partion(a, b, l, r);
    QuickSort(a, b, l, p - 1);
    QuickSort(a, b, p + 1, r);
}