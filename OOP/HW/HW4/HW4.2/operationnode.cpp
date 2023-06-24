#include "operationnode.h"

void OperationNodePlus::calc()
{
    // 递归计算
    input1->calc();		
    input2->calc();		
	// 更新当前节点值 (根据input1和input2的value进行加法/减法)
    UpdateValue();
}
void OperationNodePlus::UpdateValue()
{
    value_ = input1->value() + input2->value();
}
void OperationNodeMinus::UpdateValue()
{
    value_ = input1->value() - input2->value();
}

void OperationNodeMinus::calc()
{
    // 递归计算
    input1->calc();		
    input2->calc();		
	// 更新当前节点值 (根据input1和input2的value进行加法/减法)
    UpdateValue();
}