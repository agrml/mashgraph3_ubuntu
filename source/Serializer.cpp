#include <string>
#include <fstream>

#include "Serializer.h"

BinarySerializerReader::BinarySerializerReader(const char *fname) {
    // unzip
    auto s = std::string(fname);
    s = std::string("unzip ") + s + ".zip";
    system(s.c_str());

    f = fopen(fname, "r");
}
BinarySerializerReader::~BinarySerializerReader() {
    fclose(f);
}

void BinarySerializerReader::InOut(int &val) {
    fread(&val, sizeof(val), 1, f);
}
void BinarySerializerReader::InOut(float &val) {
    fread(&val, sizeof(val), 1, f);
}
void BinarySerializerReader::InOut(std::string &val) {
    size_t len;
    fread(&len, sizeof(len), 1, f);
    char *s = new char[len + 1];
    fread(s, len, 1, f);
    s[len] = 0;
    val = std::string(s);
    delete s;
}

BinarySerializerWriter::BinarySerializerWriter(const char *fname) {
    fname_ = std::string{fname};
    f = fopen(fname, "w");
}
BinarySerializerWriter::~BinarySerializerWriter() {
    fclose(f);
    // zip
    auto s = std::string("zip ") + fname_ + ".zip " + fname_;
    system(s.c_str());
}

void BinarySerializerWriter::InOut(int &val) {
    fwrite(&val, sizeof(val), 1, f);
}
void BinarySerializerWriter::InOut(float &val) {
    fwrite(&val, sizeof(val), 1, f);
}
void BinarySerializerWriter::InOut(std::string &val) {
    size_t len = val.size();
    fwrite(&len, sizeof(len), 1, f);
    fwrite(val.data(), len, 1, f);
}

TextSerializerReader::TextSerializerReader(const char *fname) : stream(fname) {}

void TextSerializerReader::InOut(int &val) {
    stream >> val;
}
void TextSerializerReader::InOut(float &val) {
    stream >> val;
}
void TextSerializerReader::InOut(std::string &val) {
    stream >> val;
}

TextSerializerWriter::TextSerializerWriter(const char *fname) : stream(fname) {}

void TextSerializerWriter::InOut(int &val) {
    stream << val << std::endl;
}
void TextSerializerWriter::InOut(float &val) {
    stream << val << std::endl;
}
void TextSerializerWriter::InOut(std::string &val) {
    stream << val << std::endl;
}
