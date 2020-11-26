#include <iostream>
#include <algorithm> //std::swap
#include <chrono>  //Timer

int BinarySearch(int* a, int n, int search) {
    int pos; //current position
    int left = 0; //left edge
    int right = n - 1;  //right edge
    while (true) {
        if (left > right)   //the gap has been narrowed to zero, search doesnt exist
            return -1;
        pos = left + (right - left) / 2;    //midpoint
        if (a[pos] < search)    //search in the second half
            left = pos + 1;
        if (a[pos] > search) //search in the first half
            right = pos - 1;
        if (a[pos] == search) //search found
            return pos;
    }
}

int QuickSortPartition(int* a, int& left, int& right) {
    int ai = a[(left + right) / 2]; //array center
    int i = left;
    int j = right;
    while (i <= j) {    //while the gap exists
        while (a[i] < ai) { //shorten the gap on the left
            i++;
        }
        while (a[j] > ai) { //shorten the gap on the right
            j--;
        }
        if (i >= j)
            break;
        std::swap(a[i++], a[j--]);  //swap the ends
    }
    return j; //the right end divides the array into two parts
}

void QuickSort(int* a, int& left, int& right) {
    if (left < right) { //while the gap exists
        int part = QuickSortPartition(a, left, right);  //single cycle iteration...
        QuickSort(a, left, part);  //...split the sorting into two subarrays
        int l = part + 1;
        QuickSort(a, l, right);
    }
}

void BubbleSort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) { //swap if the left number is greater than the right one.
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

int BogoSortCorrect(int* a, int n) { //whether the array is sorted
    while (--n > 0) {
        if (a[n - 1] > a[n])
            return 0;
    }
    return 1;
}

void BogoSortShuffle(int* a, int n) {   //random sort
    for (int i = 0; i < n; ++i) {
        std::swap(a[i], a[(rand() % n)]);
    }
}

void BogoSort(int* a, int n) {  //randomly sorted until it is correct
    while (!BogoSortCorrect(a, n))
        BogoSortShuffle(a, n);
}

void CountingSort(char* a, int n) {
    const int k = 256;      //maximum number of different chars
    char c[k];  //array of different chars
    int pos = 0;
    for (int i = 0; i < k; i++) {
        c[i] = 0;   
    }
    for (int i = 0; i < n; i++) {
        c[a[i]] = c[a[i]] + 1;  //number of different chars
    }
    for (int i = 0; i < k; i++) { //char 'k'
        for (int j = 0; j < c[i]; j++) { //number of char 'k'
            a[pos] = i;
            ++pos;
        }
    }
}

void print(int* a, int n) { //print array
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

class Timer{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now()){
    }

    void reset(){
        m_beg = clock_t::now();
    }

    double elapsed() const{
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

int main(){
    srand(time(0));
    const int n = 10;
    int l = 0;
    int r = n - 1;
    int a[n];
    int b[n];
    int c[5]{-5, -67, 0, 11, -2};
    char d[n]{'4', '2', 'f', 'a', 'c', '7', 'P', '4', 'Z', '\0'};
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100 - 50;
        b[i] = rand() % 100 - 50;
    }
    QuickSort(a, l, r);
    BubbleSort(b, n);
    BogoSort(c, 5);
    CountingSort(d, n-1);
    print(a, n);
    print(b, n);
    print(c, 5);
    std::cout << d << std::endl;
    std::cout << BinarySearch(c, n, 0);
}