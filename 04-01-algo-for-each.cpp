#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;
    
template<typename T>
struct Sum{
    using value_type = T;

    T sum;
    Sum() : sum{} {}
    void operator()(T i){ sum += i;}
};

template<typename T>
void print(T val){
    cout << val << " ";
};

int main(){

    vector<int> numbers{2,4,6,8,10,12,14,16};

    std::function<void (int)> printFunction(&print<int>);
    cout << endl;

    for_each(begin(numbers), end(numbers), printFunction);
    cout << endl;
     
    for_each(begin(numbers), end(numbers), [](int& i){ i += i;});

    for_each(begin(numbers), end(numbers), printFunction);

    cout << endl;

    Sum<int> sum = for_each(begin(numbers), end(numbers), Sum<int>());

    cout << sum.sum << endl;

    return 0;
}
