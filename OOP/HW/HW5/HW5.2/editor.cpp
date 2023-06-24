#include "editor.h"

bool TextEditor::isEnd() // 判断是不是最后一行
{
    return (csr.beg.first == data.size() - 1);
}

bool TextEditor::isLineEnd() // 判断光标是否在行末尾
{
    if(isEnd()) return (data[csr.beg.first].size() == csr.beg.second);
    return (data[csr.beg.first].size() == 1 + csr.beg.second);
}

void TextEditor::check() // 对于选中区域进行删除
{
    if (isSelected)
    {
        const Position &beg = csr.beg;
        const Position &end = csr.end;
        if (beg.first == end.first) // 同行
        {
            string &str = data[beg.first];
            str.erase(str.begin() + beg.second, str.begin() + end.second);
        }
        else
        {
            string &str1 = data[beg.first];
            string &str2 = data[end.first];
            str1.erase(str1.begin() + beg.second, str1.end());
            str2.erase(str2.begin(), str2.begin() + end.second);
            str1 += str2;
            data.erase(data.begin() + beg.first + 1, data.begin() + end.first + 1);
        }
    }
    isSelected = false;
    if (data.size() == 0)
    {
        string str;
        data.push_back(str);
    }
}

TextEditor::TextEditor() : isSelected(false)
{
    string str;
    data.push_back(str);
    csr.beg = make_pair(0, 0);
}

void TextEditor::moveCursor(Position dest)
{
    csr.beg = dest;
    isSelected = false;
}

void TextEditor::select(Position beg, Position end)
{
    isSelected = true;
    csr.beg = beg;
    csr.end = end;
}

void TextEditor::screenShot()
{
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size() || (i == data.size() - 1 && j == data[i].size()) /*最后一行末尾无\n*/; j++)
        {
            if (csr.beg == make_pair(i, j))
                cout << '*';
            if (isSelected && csr.end == make_pair(i, j))
                cout << '*';
            if(j != data[i].size()) cout << data[i][j];
        }
    }
}

void TextEditor::write(const string &str)
{
    check();
    Position &beg = csr.beg;
    string str1(data[beg.first], 0, beg.second);
    string str2(data[beg.first], beg.second, data[beg.first].size() - beg.second);
    data[beg.first] = str1 + str + str2;
    beg.second += str.size();
}

void TextEditor::newline()
{
    check();
    Position &beg = csr.beg;
    string &str = data[beg.first];
    if (isEnd())
    {
        string str1(str, beg.second, str.size() - beg.second); // 没有换行符
        str.erase(str.begin() + beg.second, str.end());
        str += '\n';
        data.insert(data.begin() + beg.first + 1, str1);
    }
    else
    {
        string str1(str, beg.second, str.size() - beg.second); // 复制换行符
        str.erase(str.begin() + beg.second, str.end() - 1);        // 保留换行符
        data.insert(data.begin() + beg.first + 1, str1);
    }
    beg.first++;
    beg.second = 0;
}

void TextEditor::del()
{
    if (isSelected)
    {
        check();
    }
    else
    {
        if(isEnd() && isLineEnd()) return;
        const Position &beg = csr.beg;
        string &str = data[beg.first];
        if (isLineEnd()) // 在行尾删除则需两行拼接
        {
            str.erase(str.end() - 1, str.end());
            string str1(data[beg.first + 1]);
            str += str1;
            data.erase(data.begin() + beg.first + 1, data.begin() + beg.first + 2);
        }
        else
        {
            str.erase(str.begin() + beg.second, str.begin() + beg.second + 1);
        }
    }
}

void TextEditor::copy()
{
    if(!isSelected) return;
    clipboard.clear();
    const Position& beg = csr.beg;
    const Position& end = csr.end;
    if(!isSelected) return;
    if(beg.first == end.first)//同行
    {
        string str(data[beg.first],beg.second,end.second - beg.second);
        clipboard.push_back(str);
    }
    else
    {
        string str1(data[beg.first],beg.second,data[beg.first].size() - beg.second);
        string str2(data[end.first],0,end.second);
        clipboard.push_back(str1);
        for(int i = beg.first + 1;i < end.first;i++)
        {
            string str(data[i]);
            clipboard.push_back(str);
        }
        clipboard.push_back(str2);
    }
}

void TextEditor::paste()
{
    check();
    if(clipboard.empty()) return;
    int size_ = clipboard.size();
    Position& beg = csr.beg;
    if(size_ == 1)
    {
        string& str = data[beg.first];
        if(clipboard[0][clipboard[0].size() - 1] == '\n')
        {
            string str1(str,beg.second,str.size() - beg.second);
            str.erase(str.begin() + beg.second,str.end());
            str += clipboard[0];
            data.insert(data.begin() + beg.first + 1,str1);
            beg.first++;
            beg.second = 0;
        }
        else
        {
            str.insert(beg.second,clipboard[0]);
            beg.second += clipboard[0].size();
        }
    }
    else
    {
        string& str = data[beg.first];
        string backup(str,beg.second,str.size() - beg.second);
        str.erase(str.begin() + beg.second,str.end());
        str += clipboard[0];
        for(int i = beg.first + 1;i < beg.first + size_ - 1;i++)
        {
            data.insert(data.begin() + i,clipboard[i - beg.first]);
        }
        string clip(clipboard[size_ - 1]);//最后一行
        if(clip[clip.size() - 1] == '\n')
        {
            data.insert(data.begin() + beg.first + size_ - 1,clip);
            data.insert(data.begin() + beg.first + size_,backup);
            beg.first += size_;
            beg.second = 0;
        }
        else
        {
            int pos = clip.size();
            clip += backup;
            data.insert(data.begin() + beg.first + size_ - 1,clip);
            beg.first += (size_ - 1);
            beg.second = pos;
        }
    }
}
