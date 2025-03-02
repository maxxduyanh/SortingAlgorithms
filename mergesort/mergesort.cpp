#include <bits/stdc++.h>

using namespace std;
using namespace chrono;


#define ll long long
#define int ll
#define MAX 10000005
const int N = 1e6 + 5;
const int INF = 1e9;
const int mod = 1e9 + 7;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
void merge(vector<double>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<double>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(vector<double>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int iTest = 1; iTest <= 10; iTest++){

        string inputFile = "Test" + to_string(iTest) + ".inp";
        string outputFile = "Test" + to_string(iTest) + ".out";

        ifstream filein(inputFile);
        ofstream fileout(outputFile);

        // if (!filein) {
        //     cerr << "Lỗi: Không thể mở file " << inputFile << endl;
        //     return 1;
        // }
        // if (!fileout) {
        //     cerr << "Lỗi: Không thể mở file " << outputFile << endl;
        //     return 1;
        // }

        int n;
        filein >> n;
        
        vector<double> arr(n);
        for (int i = 0; i < n; i++){
            filein >> arr[i];
        }

        // // Kiểm tra nếu dữ liệu đọc từ file là toàn số 0
        // cout << "Dữ liệu từ file " << inputFile << ": ";
        // for (double x : arr) cout << x << " ";
        // cout << endl;

        
        //hàm tính thời gian chạy
        auto start = high_resolution_clock::now();

       mergeSort(arr, 0, n-1);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Test " << iTest << " " << duration.count() << " ms\n"; 

        fileout << n << "\n";

        fileout << duration.count() << " ms\n";
        
        for(double x : arr){
            fileout << x << " ";
        }

        filein.close();
        fileout.close();
    }

    return 0;
}

