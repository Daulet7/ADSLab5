#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class minheap{
    public:
    vector<long long> a;

    long long size(){
        return a.size();
    }

    long long parent(long long i){
        return(i-1)/2;
    }
    long long left(long long i){
        return i * 2 +1;
    }
    long long right(long long i){
        return i* 2 + 2;
    }

    long long getmin() {
        return a[0];
    }

    void insert(long long k){
        a.push_back(k);
        long long ind = a.size() - 1;
        while(ind>0 && a[ind]<a[parent(ind)]){
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(long long i){
        if(left(i) > a.size() - 1){
            return;
        }
        long long j = left(i);
        if(right(i)<a.size() && a[right(i)] < a[left(i)]){
            j = right(i);
        }

        if(a[i]>a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    long long extractmin(){
        long long root_value = getmin();

        swap(a[0], a[a.size()-1]);
        a.pop_back();

        if(!a.empty()){
            heapify(0);
        }
        return root_value;
    }
};

int main(){
    long long n;
    cin >> n;
    minheap arr;

    for(long long i = 0; i<n; i++){
        long long b;
        cin >> b;
        arr.insert(b);
    }
    long long sum = 0;
    while(arr.size()!=1){
        long long m = arr.extractmin();
        long long n = m + arr.extractmin();
        sum = sum + n;
        arr.insert(n);
    }
    cout << sum;
    return 0;
}