**2**
B.str.c_str()返回值为const char*，为C风格常量字符指针，不可进行修改
C.拷贝复制，新建一块地址，str1和str2无关系
D.str4和str3都是字符指针，他们指向同一片内存
**3**
A.scanf是在运行期完成的解析
B.str()方法返回的是stringstream的buffer内容，不仅仅是未读取内容
**4**
A.func2通过()实例化，（3）处的F2为函数对象
B.func2是一个函数类，不能直接将他作为参数传入，需要将其实例化
C.传入参数既可以是**函数指针**（即指向一个函数的指针 .eg F1）也可以是**函数对象**（即像函数的对象 .eg F2）
D.否则无法外部调用，用起来就不像函数了，不符合ducking type
**5**
B.应该传入函数对象comp，comp()无意义
D.sort方法默认以升序排列，即调用less方法，其中涉及到<运算符，则合理重载<运算符即可完成排序
**6**
A.shared_pointer会发生内存泄漏（环状结构）
B.在初始化过程中会调用辅助指针构造函数，该辅助指针中的指针成员是裸指针的拷贝。如果用同一个裸指针初始化多个shared_ptr，则他们辅助指针所指向的地址一样，但是计数并不会加和，导致一旦其中一个被delete了，所指向的内存就会被delete
C.unique_ptr不可以复制但可以移动
D.还是可以计数，只不过是创建辅助指针与析构时不会改变计数
**7**
A.模板方法是通过继承基类实现具体的子类，策略模式是将多种策略方法组合来形成对应的类
C.模板方法对于结构稳定，算法分类简单，实现复杂的业务更优，而策略模式对于结构不稳定，算法分类复杂的业务更优
D.模板方法封装性更好，策略模式因为需要选择策略方法，客户就会知道有哪些选择方式，而模板方法的策略选择已经被包装到相应的具体类中，客户不知道所选策略
**8**
B.此为行为模式