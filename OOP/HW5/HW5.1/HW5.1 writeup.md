**1**
可以在任何位置为命名空间添加新的成员
**2**
B.std::tie的形参必须为左值引用，其为解包过程的根本
C.尖括号内部内容必须在编译时确定，不可为变量
D.在编译时即被确定
E.std::tie可以用来快速获取tuple对象各个数据，即为**解包**
**3**
A.end返回的是最后一位的下一个，*(end-1)才会输出相应结果
B.执行4/3次
C.不会报错
E.该函数未被重载
**4**
A.创建了两个局部key Carol和Dave，Carol默认value为0，二者函数体外被析构
B.map容器保证key均不相同，由于已经存在Alex这个key，所以insert失效
C.传入参数不是引用，退出函数后value被还原
D.声明map时所用为**降序排列**（降序排列用greater），Bob > Alex，则先输出Bob对应的value
E.erase(iterator ita,iterator itb)删除为左闭右开，最后会剩下最后一个元素
**5**
E.需要建立映射关系，应该用map
**6**

**7**
B.若通过push_back后size超过了capacity那么就会将原来所有的元素转移到新的一片空间，也会导致原有迭代器失效
**8**
