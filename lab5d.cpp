#include <iostream>
#include <vector>
using namespace std;

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
    minheap arr;
    long long n, m;
    cin >> n >> m;
    for(long long i = 0; i<n; i++){
        long long a;
        cin >> a;
        arr.insert(a);
    }
    long long count = 0;
    while(arr.getmin()<m){
        if(arr.size()==1){
            cout << -1;
            return 0;
        }
        long long a = arr.extractmin();
        long long b = arr.extractmin();
        long long s = a + 2*b;
        arr.insert(s);
        count++;
    }
    cout << count;
    return 0;
}