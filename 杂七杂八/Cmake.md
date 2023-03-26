设置编译器的选项:

```
#设置编译器的启用所有警告
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
```

CMAKE_CXX_FLAGS是编译器的所有参数

${CMAKE_CXX_FLAGS}这个是获取所有参数的变量

所以这里就是在所有参数结尾加上-Wall
