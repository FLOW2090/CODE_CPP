#pragma once
# include <string>

using std::string;

class EncryptStrategy{
public:
	virtual string encode(string mes) = 0;
};

class InsertStrategy : public EncryptStrategy{
public:
	string encode(string mes) override {
		int size = 2 * mes.size();
		for(int i = 1;i <= size;i += 2)
		{
			mes.insert(mes.begin() + i,'#');
		}
		return mes;
	}
};

class InvertStrategy : public EncryptStrategy{
public:
	string encode(string mes) override {
		string tmp;
		for(int i = mes.size() - 1;i >= 0;i--)
		{
			tmp += mes[i];
		}
		return tmp;
	}
};