#include "editor.h"
#include <iostream>

TextEditor::TextEditor(){}

void TextEditor::moveCursor(Position dest)
{
    cursor.first = dest;
    dest.second++;
    cursor.second = dest;
}

void TextEditor::select(Position beg, Position end)
{
    cursor.first = beg;
    end.second++;
    cursor.second = end;
}

void TextEditor::write(const std::string& str)
{
    //删除选中区域内容
    auto beg = cursor.first;
    auto end = cursor.second;
    auto &tmp = data[beg.first];
    if(end.first - beg.first >= 2)
    {
        tmp.erase(beg.second,tmp.size());
        data[end.first].erase(0,end.second);
        data.erase(data.begin() + beg.first + 1,data.begin() + end.first);
    }
    else
    {
        tmp.erase(beg.second,end.second);
    }

    tmp.insert(beg.second,str);
    cursor.second = beg;
}

void TextEditor::newline()
{
    //删除选中区域内容
    auto beg = cursor.first;
    auto end = cursor.second;
    auto &tmp = data[beg.first];
    if(end.first - beg.first >= 2)
    {
        tmp.erase(beg.second,tmp.size());
        data[end.first].erase(0,end.second);
        data.erase(data.begin() + beg.first + 1,data.begin() + end.first);
    }
    else
    {
        tmp.erase(beg.second,end.second);
    }

    std::string left(tmp,beg.second,tmp.size() - beg.second);
    tmp.erase(beg.second,tmp.size());
    data.insert(data.begin()+beg.first+1,left);
    cursor.second = beg;
}

void TextEditor::del()
{
    //删除选中区域内容
    auto beg = cursor.first;
    auto end = cursor.second;
    auto &tmp = data[beg.first];
    if(end.first - beg.first >= 2)
    {
        tmp.erase(beg.second,tmp.size());
        data[end.first].erase(0,end.second);
        data.erase(data.begin() + beg.first + 1,data.begin() + end.first);
    }
    else
    {
        tmp.erase(beg.second,end.second);
    }

    if(beg.second == tmp.size())
    {
        if(beg.first == data.size() - 1) return;
        else
        {
            std::string left(data[beg.first+1],0,data[beg.first+1].size());
            data.erase(data.begin()+beg.first+1,data.begin()+beg.first+2);
            tmp += left;
        }
    }
    else
    {
        tmp.erase(beg.second,beg.second+1);
    }
    cursor.second = beg;
}

void TextEditor::copy()
{
    auto beg = cursor.first;
    auto end = cursor.second;
    clipboard.clear();
    if(beg.first == end.first)//复制只涉及单行
    {
        std::string str(data[beg.first],beg.second,end.second - beg.second);
        clipboard.push_back(str);
    }
    else
    {
        for(int i = 0;i < end.first - beg.first;i++)
        {
            if(i == 0)
            {
                std::string str(data[beg.first],beg.second,data[beg.first].size() - beg.second);
                clipboard.push_back(str);
            }
            else if(i == end.first - beg.first - 1)
            {
                std::string str(data[end.first],0,end.second);
                clipboard.push_back(str);
            }
            else
            {
                std::string str(data[i+beg.first],0,data[i+beg.first].size());
                clipboard.push_back(str);
            }
        }
    }
}

void TextEditor::paste()
{
    //删除选中区域内容
    auto beg = cursor.first;
    auto end = cursor.second;
    auto &tmp = data[beg.first];
    if(end.first - beg.first >= 2)
    {
        tmp.erase(beg.second,tmp.size());
        data[end.first].erase(0,end.second);
        data.erase(data.begin() + beg.first + 1,data.begin() + end.first);
    }
    else
    {
        tmp.erase(beg.second,end.second);
    }

    for(int i = 0;i < clipboard.size();i++)
    {
        if(i == 0)
        {
            std::string str(tmp,beg.second,data[beg.first].size() - beg.second);
            tmp.erase(beg.second,tmp.size());
            tmp += clipboard[0];
            tmp += str;
        }
        else if(i != clipboard.size() - 1)
        {
            data.insert(data.begin() + beg.first + i,clipboard[i]);
        }
        else
        {
            data[beg.first + i] = clipboard[i] + data[beg.first + i];
        }
    }
}

void TextEditor::screenShot()
{
    for(int i = 0;i < data.size() || (i == 0 && data.size() == 0);i++)
    {
        if(i != 0) std::cout << std::endl;
        for(int j = 0;(j == 0 && data.size() == 0) || j < data[i].size();i++)
        {
            if((cursor.first.first == i && cursor.first.second == j)
            ||(cursor.second.first == i && cursor.second.second == j))
            {
                std::cout << '*';
            }
            if(data.size() != 0) std::cout << data[i][j];
            else break;
        }
    }
}

