#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArray(n1), rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    srand(time(0));

    std::vector<int> sizes = { 100, 1000, 2000, 3000, 4000, 5000 };

    for (int size : sizes) {
        // Generate a random list
        std::vector<int> vec(size);
        for (int i = 0; i < size; i++) {
            vec[i] = rand() % 1000;
        }

        // Measure the time taken to sort
        clock_t start = clock();
        mergeSort(vec, 0, size - 1);
        clock_t end = clock();

        double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "Size: " << size << ", Time: " << elapsed_time << " seconds\n";
    }

    return 0;
}
