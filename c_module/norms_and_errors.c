#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>


static PyObject* norm_one_vector(PyObject* self, PyObject* args) {
    PyObject *listObj;
    double suma = 0.0;

    if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &listObj)) {
        return NULL;
    }

    Py_ssize_t len = PyList_Size(listObj);
    for (Py_ssize_t i = 0; i < len; i++) {
        PyObject *item = PyList_GetItem(listObj, i);
        if (!PyFloat_Check(item) && !PyLong_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "The list must contain only numbers.");
            return NULL;
        }
        double number = PyFloat_AsDouble(item);
        if (number < 0){
            number = -number;
        }
        
        suma += number;
    }

    return PyFloat_FromDouble(suma);
}


static PyMethodDef norms_and_errors_methods[] = {
    {"norm_one_vector", norm_one_vector, METH_VARARGS, "norm one vector"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef norms_and_errors_module = {
    PyModuleDef_HEAD_INIT,
    "norms_and_errors",
    NULL,
    -1,
    norms_and_errors_methods
};

PyMODINIT_FUNC PyInit_norms_and_errors(void){
    return PyModule_Create(&norms_and_errors_module);
}


