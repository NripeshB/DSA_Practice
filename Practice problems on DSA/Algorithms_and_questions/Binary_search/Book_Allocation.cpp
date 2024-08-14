//https://www.naukri.com/code360/problems/allocate-books_1090540?count=25&page=1&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=SUBMISSION
//The code below is the solution for the question above

#include <iostream>
#include <vector>
using namespace std;


bool ispossible(vector<int> &arr, int m, int n, int Mid) {
    int pagecount = 0;
    int studentcount = 1;
    for(int i = 0; i < n; i++){
        if(pagecount + arr[i] <= Mid){
            pagecount += arr[i];
        } else {
            studentcount++;
            if(studentcount > m || arr[i] > Mid){
                return false;
            }
            pagecount = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    int sum = 0;
    if (m > n) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int s = 0;
    int e = sum;
    int ans = -1;
    while(s <= e){
        int Mid = s + ((e - s) / 2); // Corrected Mid calculation
        if(ispossible(arr, m, n, Mid)){
            ans = Mid;
            e = Mid - 1;
        } else { 
            s = Mid + 1;
        }
    }
    return ans;
}


int main() {
    int n, m;
    cout << "Enter the number of books: ";
    cin >> n;
    
    cout << "Enter the number of students: ";
    cin >> m;

    vector<int> arr(n);
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findPages(arr, n, m);

    if (result == -1) {
        cout << "It is not possible to allocate books to students." << endl;
    } else {
        cout << "The minimum number of pages that can be allocated to students is: " << result << endl;
    }

    return 0;
}
