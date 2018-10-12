#ifndef OPENTURNS_PYTHONFIELDFUNCTION_HXX
#define OPENTURNS_PYTHONFIELDFUNCTION_HXX

#include "Python.h"
#include "FieldFunctionImplementation.hxx"

namespace OT {
  class PythonFieldFunction : public FieldFunctionImplementation
  {
  public:
    explicit PythonFieldFunction(PyObject * pyCallable = 0);

  private:
    PyObject * pyObj_;
  };
}

#endif
