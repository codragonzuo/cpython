#include <Python.h>
//#include "structmember.h"
#include <stdlib.h>
#include <stdio.h>
#include "cmodule.h"
#include <string.h>

//using namespace std;

//#ifdef __cplusplus
extern "C" {
//#endif
static void **PyAcd_API;
static PyObject *AcdError;

/* declare */
static int PyAcd_System(const char *command);

/*
>>> acd.addrule((2,3),[(6,9,8),(5,10,1)])
id=2 type=3
length=2
type=6  data1=0x9  data2=0x8
type=5  data1=0xa  data2=0x1
addrule  rc=0
0
*/


/**************************************************/
static int PyAcd_System(const char *command)
{
    return system(command);
}


static PyObject * acd_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;


    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = PyAcd_System(command);

    return Py_BuildValue("i", sts);
}

struct T_RuleData
{
    unsigned long    m_Id;     
    unsigned char    m_Type;   
};

struct T_Pa
{
    unsigned long data;
    unsigned long mask;
};

struct T_Rule
{
    unsigned long    wType;
    T_Pa           tPa;
};

static PyObject * addrule(PyObject *self, PyObject *args)
{
    int rc;
    int type;
    unsigned long long data1;
    unsigned long long data2;
    T_RuleData ruledata;
    T_Rule  * allrule;
    T_Rule  * rule;
    PyObject  * listObj;
    PyObject  * strObj;

    //&PyList_Type, 
    if (!PyArg_ParseTuple(args,"(ii)O",&ruledata.m_Id, &ruledata.m_Type, &listObj))
                  
    {
        printf("ERROR");
        return NULL;
    }
    
    printf("id=%d type=%d \n", ruledata.m_Id, ruledata.m_Type);
         
    PyObject * tempObj;                   
    long length= PyList_Size(listObj);
    printf("length=%d\n", length);
    allrule = (T_Rule  *)malloc(length*sizeof(T_Rule));
    if (rule == 0) 
    {
        rc = 1;  
        return Py_BuildValue("i", rc);
    }
    
    int i;
    for (i=0; i<length; i++)
    {
        rule = &allrule[i];
        tempObj=PyList_GetItem(listObj, i);
        if (!PyArg_ParseTuple(tempObj,"iLL",&type, &data1, &data2))
        {
        printf("ERROR");
        return NULL;
        }
        printf("type=%d  data1=0x%llx  data2=0x%llx\n", type, data1, data2);
        rule->wType = type;
        rule->tPa.data = data1;
        rule->tPa.mask = data2;
    }

    //call something
    printf("addrule  rc=%d\n", rc);
    
    return Py_BuildValue("i", rc);
}


 
static PyMethodDef AcdMethods[] = {  
    {"system",          acd_system,             METH_VARARGS,   "Execute a shell command."},  
    {"addrule",         addrule,                METH_VARARGS,   "add rule, "},  
    {NULL, NULL, 0, NULL}  
}; 


//#ifndef PyMODINIT_FUNC	/* declarations for DLL import/export */
//#define PyMODINIT_FUNC extern "C" void
//#endif


PyMODINIT_FUNC initacd(void)
{
    PyObject *m;
    static void *PyAcd_API[PyAcd_API_POINTERS];
    PyObject *c_api_object;
    PyObject *c_rule_object;
    

    m = Py_InitModule("acd", AcdMethods);
    if (m == NULL)
        return;

    /* Initialize the C API pointer array */
    PyAcd_API[PyAcd_SYSTEM_NUM] = (void *)PyAcd_System;

    /* Create a Capsule containing the API pointer array's address */
    c_api_object = PyCapsule_New((void *)PyAcd_API, "acd._C_API", NULL);

    if (c_api_object != NULL)
        PyModule_AddObject(m, "_C_API", c_api_object);
}


static int import_acd(void)
{
    PyAcd_API = (void **)PyCapsule_Import("acd._C_API", 0);
    return (PyAcd_API != NULL) ? 0 : -1;
}



//#ifdef __cplusplus
}
//#endif
