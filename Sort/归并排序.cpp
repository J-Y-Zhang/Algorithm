#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &arr, int l, int r) {
    // �ݹ�߽�, 1��Ԫ�ز�������
    if (l >= r) {
        return;
    }

    int mid = (l + r) >> 1;

    // 1.�Ƚ������ź���
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    // 2.�鲢
    vector<int> temp;   
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        temp.push_back(arr[i] < arr[j] ? arr[i++] : arr[j++]);
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= mid) {
        temp.push_back(arr[j++]);
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[l + i] = temp[i];
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3, 1, 5, 8, 0, 5, 2, 6};
    merge_sort(arr, 0, arr.size() - 1);
    cout << "�鲢����" << endl;
    for (const auto& val : arr) {
        printf("%d ", val);
    }
    return 0;
}