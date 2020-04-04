#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

#include "universal_out_map_vector_pair.h"
using namespace std;
template<typename T> T Sqr(T x);

template <typename T>
T Sqr(T x) {
    return x*x;
}
template <typename First,typename Second>
pair<First,Second> operator * (const pair<First, Second>& p1,const pair<First, Second>& p2){
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return make_pair(f, s);
}
template <typename T>
vector<T> operator * (vector<T>& v1, const vector<T>& v2) {
    if (v1.size() == v2.size()) {
        for (int i = 0; i < v1.size(); i++) {
            v1[i] = v1[i] * v2[i];
        }
        return v1;
    }
    else {
        stringstream ss;
        ss << "expected vectors with one size, but has: " << v1.size() << " and " << v2.size();
        throw runtime_error(ss.str());
    }
}
template <typename Key,typename Value>
map<Key, Value> operator * (map<Key, Value> m1,map<Key,Value> m2){
    if (m1.size() == m2.size()) {
        for(auto& [key,value]: m1){
            value = value * value;
        }
        return m1;
    }
    else {
        stringstream ss;
        ss << "expected maps with one size, but has: " << m1.size() << " and " << m2.size();
        throw runtime_error(ss.str());
    }
}
int main() {
    vector<double> vi = {1.4, 2, 3};
    cout <<  Sqr(vi)<< endl;
    map<int, double> m = {{1, 2.5}, {3, 4}};
    cout <<  Sqr(m)<< endl;
    vector<vector<int>> v = {{1, 2}, {3, 4}};
    cout << Sqr(v)<< endl;
    return 0;
}