#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

class heap{
    public:
    vector<long long> a;

    long long size(){
        return a.size();
    }

    long long parent(long long i){
        return (i-1)/2;
    }

    long long left(long long i){
        return i*2 + 1;
    }

    long long right(long long i){
        return i*2+2;
    }

    long long getmax(){
        return a[0];
    }

    void insert(long long k){
        a.push_back(k);
        long long index = a.size()-1;
        while(index>0 && a[index]>a[parent(index)]){
            swap(a[index], a[parent(index)]);
            index = parent(index);
        }
    }

    void heapify(long long i){
        if(left(i) > a.size() - 1){
            return;
        }
        long long j = left(i);
        if(right(i)<a.size() && a[right(i)] > a[left(i)]){
            j = right(i);
        }
        if(a[j]>a[i]){
            swap(a[j], a[i]);
            heapify(j);
        }
    }

    long long pop_max(){
        long long v = a[0];
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        if(!a.empty()){
            heapify(0);
        }
        return v;
    }
};

int main(){
    long long n, x;
    cin >> n >> x;
    heap arr;
    for(long long i = 0; i<n; i++){
        long long a;
        cin >> a;
        arr.insert(a);
    }
    long long sum = 0;
    while(x!=0){
        long long a = arr.pop_max();
        sum += a;
        arr.insert(a-1);
        x--;
    }
    cout << sum;
    return 0;
}