#include "graph.h"
#include "operationnode.h"

Graph::Graph(int num_node) {
    // 预分配节点空间
    nodes_.initialize(num_node);
}

void Graph::InsertPlaceholder(const string &node_name) {
    Node *tmp = new PlaceholderNode(node_name);
    nodes_.insert(node_name,tmp);
    // wait to fill, 使用nodes_.insert()新建一个占位符
}

void Graph::InsertConstant(const string &node_name, float value) {
    Node *tmp = new ConstantNode(node_name,value);
    nodes_.insert(node_name,tmp);
    // wait to fill, 使用nodes_.insert()新建一个常量
}

void Graph::InsertOperation(const string &node_name, const string &operation_type, 
                                const string &input1, const string &input2) {
    Node *left = nodes_[input1];
    Node *right = nodes_[input2];
    if(left == nullptr || right == nullptr) return;
    if(operation_type == "+")
    {
        OperationNodeTwo *tmp = new OperationNodePlus(node_name,left,right);
        nodes_.insert(node_name,tmp);
    }
    else if(operation_type == "-")
    {
        OperationNodeTwo *tmp = new OperationNodeMinus(node_name,left,right);
        nodes_.insert(node_name,tmp);
    }
    // wait to fill, 根据operation_type的名字调用相应的运算符节点构造函数
}

void Graph::Eval(const string &node_name, const int &argument_num, 
                    const string* argument_name_list_, const float* argument_value_list_) {
    for(int i = 0;i < argument_num;i++)
    {
        auto *tmp = dynamic_cast<PlaceholderNode*>(nodes_[argument_name_list_[i]]);
        (*tmp).set_val(argument_value_list_[i]);
    }
    // wait to fill, 调用相应的placeholder的set_val函数

    nodes_[node_name]->calc();
    float temp_value = nodes_[node_name]->value();
    cout << std::fixed << setprecision(2) << temp_value << endl;   
}

Graph::~Graph() {
    
}


