
#ifndef Py_ACDMODULE_H
#define Py_ACDMMODULE_H


//#ifdef __cplusplus
extern "C" {
//#endif

#define PyAcd_SYSTEM_RETURN (int)
#define PyAcd_SYSTEM_NUM 0
#define PyAcd_API_POINTERS 1
#define PyAcd_SYSTEM_PROTO (const char *command)
#define PyAcd_SYSTEM  (*(PyAcd_SYSTEM_RETURN (*)PyAcd_SYSTEM_PROTO) PyAcd_API[PyAcd_SYSTEM_NUM])

PyMODINIT_FUNC initacd(void);
static int import_acd(void);
static PyObject * acd_system(PyObject *self, PyObject *args);



//#ifdef __cplusplus
}
//#endif

#endif /* !defined(Py_ACDMODULE_H) */

