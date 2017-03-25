### python_api 
The code work fine in Python 3.x. 
you create a `PyModuleDef` structure and then pass a reference to it to `PyModule_Create`.   
but in Python 2.x.  you need to use `Py_InitModule` 

命令行执行编译
```
python setup.py build
```
编译成功后可以测试
```
>>> import fac_module
>>> fac_module.fac_function(3)
>>> 6
```
---

### python_SWIG

SWIG的安装方便，有Windows的预编译包，解压即用，绿色健康。

除了SWIG，市面上还有若干用于Python扩展的工具包，比较知名的还有Boost.Python、SIP等，此外，Cython由于可以直接集成C/C++代码，并方便的生成Python模块，故也可以完成扩展Python的任务。

使用SWIG将这个配置文件编译为所谓Python Module Wrapper
```
swig -python fac_module.i
```

这个配置文件分为3个部分：
* 定义module名称fac_module，通常，module名称要和文件名保持一致。
* %{ %} 包裹的部分是C语言的代码，这段代码会原封不动的复制到fac_module_wrap.c
* 欲导出的函数签名列表。直接从头文件里复制过来即可。

生成的XXX_warp.c和XXX.py文件.把它编译为Python扩展：

```
cl /LD fac_module_wrap.c /o _fac_module.pyd -ID:\Python34\include D:\Python34\libs\python34.lib
```
注意输出文件名前面要加一个下划线`_fac_module.pyd`.
现在可以立即在Python下使用这个module了.

---

### SWIG_C++
对于C++，SWIG也可以应对。

`xxx.h` 和`xxx.i`文件 （`xxx.cpp`）
SWIG编译时要加-c++这个选项，生成的扩展名为cxx
```
swig -c++ -python show_class.i
```
Windows下编译：
打开VS 命令提示符
```
cl /LD show_class_wrap.cxx /o _show_class.pyd -ID:\Python34\include D:\Python34\libs\python34.lib
```
最后在Python交互模式下测试：
```
>>>import show_class
>>>a = show_class.Show()
>>>a.setnum(5)
>>>a.getnum()
>>>5
```
也就是说C++的class会直接映射到Python class
