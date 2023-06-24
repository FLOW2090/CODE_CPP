#pragma once
# include <string>

using std::string;

class VerificationStrategy{
public:
	virtual string verify(string mes) = 0;
};

class PrefixStrategy : public VerificationStrategy{
public:
	string verify(string mes) override {
		string tmp(mes,0,3);
		return tmp;
	}
};

class IntervalStrategy : public VerificationStrategy{
public:
	string verify(string mes) override {
		string tmp;
		for(int i = 0;i < mes.size();i += 2)
		{
			tmp += mes[i];
		}
		return tmp;
	}
};