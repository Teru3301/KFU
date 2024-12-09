#pragma once


class IntSharedPointer {
private:
    int* refs;
    int* p;
    void decreaseRefs() {
        (*refs)--;
        if (*refs == 0) {
            delete p;
            delete refs;
        }
    }
    void copyRefs(const IntSharedPointer& b) {
        p = b.p;
        refs = b.refs;
        (*refs)++;
    }
public:
    IntSharedPointer(int* pointer) {
        refs = new int{1};
        p = pointer;
    }
    IntSharedPointer(IntSharedPointer& b) {
        copyRefs(b);
    }
    ~IntSharedPointer() {
        decreaseRefs();
    }
    int& operator*() {
        return *p;
    }
    IntSharedPointer& operator=(const IntSharedPointer& b) {
        if (this == &b) {
            return *this;
        }
        decreaseRefs();
        copyRefs(b);
        return *this;
    }
};
