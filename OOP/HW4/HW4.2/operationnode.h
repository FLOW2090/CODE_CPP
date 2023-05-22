#pragma once
#include "operation.h"

class OperationNodePlus : public OperationNodeTwo {
    public:
        OperationNodePlus(string name, Node *x1, Node *x2) : OperationNodeTwo(name, x1, x2) {};
        void calc() override;
        void UpdateValue() override;
};

class OperationNodeMinus : public OperationNodeTwo {
    public:
        OperationNodeMinus(string name, Node *x1, Node *x2) : OperationNodeTwo(name, x1, x2) {};
        void calc() override;
        void UpdateValue() override;
};