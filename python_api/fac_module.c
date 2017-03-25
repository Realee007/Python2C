#include <Python.h>

int fac_function(int n){
	if (n > 1)
	{
		return n*fac_function(n - 1);
	}
	return 1;
}

static PyObject* _fac_function(PyObject *self, PyObject *args)
{
	int _n;
	int res;
	if (!PyArg_ParseTuple(args, "i", &_n))
		return NULL;
	res = fac_function(_n);
	return PyLong_FromLong(res);
}

static PyMethodDef facModuleMethods[] = {
	{ 
		"fac_function", 
		_fac_function, 
		METH_VARARGS, 
		"the factorial of a non-negative integer n" 
	},
	{ NULL, NULL, 0, NULL }
};

static  struct PyModuleDef fac_module =
{
	PyModuleDef_HEAD_INIT,
	"fac_module",
	"",
	-1,
	facModuleMethods
};


PyMODINIT_FUNC PyInit_fac_module(void)
{
	PyObject *m;
	m = PyModule_Create(&fac_module);
	if (m == NULL)
		return NULL;
	printf("init fac_module module\n");
	return m;
}
