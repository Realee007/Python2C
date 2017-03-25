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
