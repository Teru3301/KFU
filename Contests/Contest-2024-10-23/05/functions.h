#pragma once 


class GreaterAdapter: public IComparator{
    using func = void (*)(int a, int b, bool& verdict);
    func cmp;
public:
    GreaterAdapter(func cmp): cmp(cmp){
    }
    
    bool compare(int a, int b) const override {
        bool res;
        cmp(a, b, res);
        return res;
    }
};

class KeyFuncLessAdapter: public IComparator{
    using func = double (*)(int value);
    func key_func;
public:
    KeyFuncLessAdapter(func key_func): key_func(key_func){
    }
    
    bool compare(int a, int b) const override {
        return key_func(a) < key_func(b);
    }
};
