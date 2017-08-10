#ifndef XA_RESULT_H
#define XA_RESULT_H

#include <iostream>
#include <functional>
#include <memory>

template<class T, class E> class Result {
private:
    union {
        T okValue;
        E errValue;
    } values;

    bool hasOkValue;

    Result();

public:

    static Result<T, E> ok(T okValue);
    static Result<T, E> error(E errorValue);

    bool isOk();
    bool isError();

    template<class U> Result<U, E> map(std::function<U(T)> mapfunc);
};

template<class T, class E> Result<T, E>::Result() {
}

template<class T, class E> Result<T, E> Result<T,E>::ok(T okValue) {
    Result<T, E> newResult;

    newResult.hasOkValue = true;
    newResult.values.okValue = okValue;

    return newResult;
}

template<class T, class E> Result<T, E> Result<T, E>::error(E errorValue) {
    Result<T, E> newResult;

    newResult.hasOkValue = false;
    newResult.values.errValue = errorValue;

    return newResult;
}

template<class T, class E> bool Result<T, E>::isOk() {
    return this->hasOkValue;
}

template<class T, class E> bool Result<T, E>::isError() {
    return !this->isOk();
}

template<class T, class E> template<class U> Result<U, E> Result<T, E>::map(std::function<U(T)> mapfunc) {
    Result<U, E> newResult;
    newResult.hasOkValue = this->hasOkValue;

    if (this->hasOkValue) {
        newResult.values.okValue = mapfunc(this->values.okValue);
    } else {
        newResult.values.errValue = this->values.errValue;
    }

    return newResult;
}


#endif // XA_RESULT_H