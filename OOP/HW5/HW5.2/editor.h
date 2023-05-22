#pragma once

#include <vector>
#include <string>
#include <list>
#include <iostream>

using std::pair;
using std::string;
using std::vector;
using Position = pair<int, int>;
using std::make_pair;
using std::cout;

struct Cursor
{
    Position beg;
    Position end;
};

class TextEditor {
private:
    Cursor csr;
    bool isSelected;
    vector<string> data; // 数据区，亦可采用其他数据结构
    vector<string> clipboard; // 剪贴板，亦可采用其他数据结构
public:
    TextEditor();
    void moveCursor(Position dest);
    void select(Position beg, Position end);
    void write(const string& str);
    void newline();
    void del();
    void copy();
    void paste();
    void screenShot();
    void check();
    bool isEnd();
    bool isLineEnd();
};