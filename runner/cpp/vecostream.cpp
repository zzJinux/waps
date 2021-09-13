#include <iostream>
#include <string>
using namespace std;

template<typename T>
ostream& operator<<(ostream &os, vector<T> const &valvec) {
    size_t N = valvec.size();
    if(N==0) {
        os << "[]";
        return os;
    }

    os << "[";
    os << valvec[0];
    for(size_t i=1; i<N; ++i) {
        os << ", " << valvec[i];
    }
    os << "]";
    return os;
}

template<>
ostream& operator<<(ostream &os, vector<bool> const &valvec) {
    size_t N = valvec.size();
    if(N==0) {
        os << "[]";
        return os;
    }

    os << "[";
    os << (valvec[0] ? "true" : "false");
    for(size_t i=1; i<N; ++i) {
        os << ", " << (valvec[i] ? "true" : "false");
    }
    os << "]";
    return os;
}

template<>
ostream& operator<<(ostream &os, vector<string> const &valvec) {
    size_t N = valvec.size();
    if(N==0) {
        os << "[]";
        return os;
    }

    os << "[";
    os << "\"" << valvec[0] << "\"";
    for(size_t i=1; i<N; ++i) {
        os << ", " << "\"" << valvec[i] << "\"";
    }
    os << "]";
    return os;
}
