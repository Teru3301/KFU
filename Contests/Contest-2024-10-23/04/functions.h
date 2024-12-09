#pragma once


Any::Any(int* data) {
    this->data = data;
    this->type = Type::INT;
}
Any::Any(double* data) {
    this->data = data;
    this->type = Type::DOUBLE;
}
Any::Any(std::string* data) {
    this->data = data;
    this->type = Type::STRING;
}
Any::Any(std::vector<Any*>* data) {
    this->data = data;
    this->type = Type::VECTOR_ANY_PTR;
}
Any::~Any() {
    if (type == Type::VECTOR_ANY_PTR) {
        auto realPtr = static_cast<std::vector<Any*>*>(data);
        for (auto &it : *realPtr) {
            delete it;
        }
        delete realPtr;
    } else if (type == Type::INT) {
        int* realPtr = static_cast<int*>(data);
        delete realPtr;
    } else if (type == Type::DOUBLE) {
        double* realPtr = static_cast<double*>(data);
        delete realPtr;
    } else if (type == Type::STRING) {
        std::string* realPtr = static_cast<std::string*>(data);
        delete realPtr;
    }
}
Any::operator int() {
    if (type != Type::INT) {
        throw "";
    }
    return *static_cast<int*>(data);
}
Any::operator double() {
    if (type != Type::DOUBLE) {
        throw "";
    }
    return *static_cast<double*>(data);
}
Any::operator std::string() {
    if (type != Type::STRING) {
        throw "";
    }
    return *static_cast<std::string*>(data);
}
Any::operator std::vector<Any*>*() {
    if (type != Type::VECTOR_ANY_PTR) {
        throw "";
    }
    return static_cast<std::vector<Any*>*>(data);
}
std::ostream& operator<<(std::ostream& out, const Any& val) {
    if (val.type == Any::Type::VECTOR_ANY_PTR) {
        auto realPtr = static_cast<std::vector<Any*>*>(val.data);
        for (auto &it : *realPtr) {
            out << *it << " ";
        }
    } else if (val.type == Any::Type::INT) {
        int* realPtr = static_cast<int*>(val.data);
        out << *realPtr;
    } else if (val.type == Any::Type::DOUBLE) {
        double* realPtr = static_cast<double*>(val.data);
        out << *realPtr;
    } else if (val.type == Any::Type::STRING) {
        std::string* realPtr = static_cast<std::string*>(val.data);
        out << *realPtr;
    }
    return out;
}
