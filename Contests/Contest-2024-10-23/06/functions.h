#pragma once


class ScreenPrintStrategy : public PrintStrategy {
public:
    void print(const Document& document) override {
        std::cout << document.get() << "\n";
    }
};

class StringPrintStrategy : public PrintStrategy {
private:
    std::string buff;
    int count;
public:
    StringPrintStrategy() {
        count = 1;
    }
    void print(const Document& document) override {
        buff += "--- doc " + std::to_string(count) + " ---\n";
        buff += document.get();
        buff += "\n";
        count++;
    }
    std::string getPrintedDocuments() {
        return buff;
    }
};

class MockPrintStrategy : public PrintStrategy {
private:
    int count;
public:
    MockPrintStrategy() {
        count = 0;
    }
    void print(const Document& document) override {
        count++;
    }
    int getPrintedDocumentsCount() {
        return count;
    }
};
