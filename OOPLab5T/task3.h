#include <iostream>
#include <cstring>

class String {
protected:
    char* buffer1;
    size_t size1;

public:
    String() : buffer1(nullptr), size1(0) {}

    String(const char* str) : buffer1(nullptr), size1(0) {
        if (str != nullptr) {
            size1 = strlen(str);
            buffer1 = new char[size1 + 1];
            strncpy_s(buffer1, size1 + 1, str, size1);
        }
    }

    String(const String& other) : buffer1(nullptr), size1(0) {
        if (other.buffer1 != nullptr) {
            size1 = other.size1;
            buffer1 = new char[size1 + 1];
            strncpy_s(buffer1, size1 + 1, other.buffer1, size1);
        }
    }

    virtual ~String() {
        delete[] buffer1;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.buffer1;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, String& str) {
        char buffer[1024];
        is >> buffer;
        str = String(buffer);
        return is;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] buffer1;
            size1 = other.size1;
            buffer1 = new char[size1 + 1];
            strncpy_s(buffer1, size1 + 1, other.buffer1, size1);
        }
        return *this;
    }
};

class DerivedString : public String {
public:
    DerivedString() : String() {}

    DerivedString(const char* str) : String() {
        if (str != nullptr) {
            size1 = strlen(str);
            buffer1 = new char[size1 + 1];
            strncpy_s(buffer1, size1 + 1, str, size1);
            if (!isDerivedString()) {
                delete[] buffer1;
                buffer1 = nullptr;
                size1 = 0;
            }
        }
    }

    DerivedString(const DerivedString& other) : String(other) {}

    virtual ~DerivedString() {}

    bool isDerivedString() const {
        // Additional logic specific to DerivedString
        return true;
    }

    DerivedString& operator=(const DerivedString& other) {
        if (this != &other) {
            String::operator=(other);
            if (!isDerivedString()) {
                delete[] buffer1;
                buffer1 = nullptr;
                size1 = 0;
            }
        }
        return *this;
    }
};
