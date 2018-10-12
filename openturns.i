
%module(docstring="Field example") openturns



// Mesh
%{
#include "Mesh.hxx"
%}

%include Mesh.hxx



// FieldFunctionImplementation
%{
#include "FieldFunctionImplementation.hxx"
%}

%include FieldFunctionImplementation.hxx



// FieldFunction
%{
#include "FieldFunction.hxx"
#include "PythonFieldFunction.hxx"
%}

%include FieldFunction.hxx

namespace OT { %extend FieldFunction { 

FieldFunction(const FieldFunction & other) { return new OT::FieldFunction(other); } 

FieldFunction(PyObject * pyObj)
{
  return new OT::FieldFunction(new OT::PythonFieldFunction(pyObj));
}


} }
