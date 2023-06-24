#include "node.h"

void PlaceholderNode::set_val(float val)
{
    value_ = val;
}

void PlaceholderNode::calc()
{
    return;
}
Node::~Node(){};