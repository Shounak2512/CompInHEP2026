#include <Python.h>
#include <iostream>
 
static PyObject* testSource(PyObject* self, PyObject* args) {
  const char* text;
 
  if (!PyArg_ParseTuple(args, "s", &text))
    return NULL;

  std::cout << text << std::endl;
 
  Py_RETURN_NONE;
}
 
static PyMethodDef MyMethods[] =
  {
    {"my_test", testSource, METH_VARARGS, "Some text."},
    {NULL, NULL, 0, NULL}
  };

static struct PyModuleDef MyModule =
{
    PyModuleDef_HEAD_INIT,
    "MyModule", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    MyMethods
};

PyMODINIT_FUNC PyInit_MyModule()
{
  return PyModule_Create(&MyModule);
}

