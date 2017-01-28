#pragma once

#include <iostream>
#include <fstream>

class ISerializer {
public:
    virtual void InOut(int &val) = 0;
    virtual void InOut(float &val) = 0;
    virtual void InOut(std::string &val) = 0;
};

class BinarySerializerReader : public ISerializer {
    FILE *f;
public:
    BinarySerializerReader(const char *fname);
    ~BinarySerializerReader();

    void InOut(int &val);
    void InOut(float &val);
    void InOut(std::string &val);
};

class BinarySerializerWriter : public ISerializer {
    FILE *f;
public:
    BinarySerializerWriter(const char *fname);
    ~BinarySerializerWriter();

    void InOut(int &val);
    void InOut(float &val);
    void InOut(std::string &val);
};

class TextSerializerReader : public ISerializer {
    std::ifstream stream;
public:
    TextSerializerReader(const char *fname);

    void InOut(int &val);
    void InOut(float &val);
    void InOut(std::string &val);
};

class TextSerializerWriter : public ISerializer {
    std::ofstream stream;
public:
    TextSerializerWriter(const char *fname);

    void InOut(int &val);
    void InOut(float &val);
    void InOut(std::string &val);
};
