#include <iostream>

bool areEqual(int arr1[], int length1, int arr2[], int length2) {
    if (length1 != length2) {
        return false;
    }

    if (arr1 == arr2) {
        return true;
    }
    else {
        for (int i = 0; i < length1; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }

        return true;
    }
}

int main() {
    int fal, sal;

    std::cin >> fal;

    int arr1[1000];

    for (int i = 0; i < fal; i++) {
        std::cin >> arr1[i];
    }

    std::cin >> sal;

    int arr2[1000];

    for (int i = 0; i < sal; i++) {
        std::cin >> arr2[i];
    }

    bool equal = areEqual(arr1, fal, arr2, sal);

    std::cout << (equal ? "equal" : "not equal") << std::endl;

    return 0;
}