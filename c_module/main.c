#include <Python.h>

static PyObject* hello_world(PyObject* self, PyObject* args) {
    return Py_BuildValue("s", "Hello from C!");
}

static PyMethodDef Methods[] = {
    {"hello_world", hello_world, METH_VARARGS, "Print Hello World from C"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "my_c_extension",
    "A simple example module",
    -1,
    Methods
};

PyMODINIT_FUNC PyInit_my_c_extension(void) {
    return PyModule_Create(&module);
}
