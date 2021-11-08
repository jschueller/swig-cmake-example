
%module(docstring="Field example") openturns

%{
#include <iostream>
%}

%include exception.i
%include std_string.i

%exception {
  std::cerr << "try..."<<std::endl;
  try {
    std::cerr << "try..."<<std::endl;
    $action
  }
  catch (std::range_error & ex) {
    std::cerr << "catch range_error"<<std::endl;
    SWIG_exception(SWIG_IndexError,ex.what());
  }
  catch (std::out_of_range & ex) {
    std::cerr << "catch out_of_range"<<std::endl;
    SWIG_exception(SWIG_IndexError,ex.what());
  }
  catch (std::logic_error & ex) { // IDM : Glut Debian Squeeze with libstdc++ 4.4.5
    std::cerr << "catch logic_error"<<std::endl;
    SWIG_exception(SWIG_IndexError,ex.what());
  }
  catch (std::exception & ex) {
    std::cerr << "catch exception"<<std::endl;
    SWIG_exception(SWIG_RuntimeError,ex.what());
  }
  std::cerr << "end catch ..."<<std::endl;
}

// Description
%{
#include "Description.hxx"
%}
%ignore OT::Description::operator[];

namespace OT {
%extend Description {
PyObject * __getitem__(PyObject * arg) const
{
  std::cout << "Description::__getitem__" << std::endl;

    swig_type_info *tq = SWIG_TypeQuery("OT::Description *");
    std::cout << "Description::__getitem__ tq=" <<tq<< std::endl;
  
  return Py_None;
}
}
}

%include Description.hxx

// Mesh
%{
#include "Mesh.hxx"
%}
%ignore OT::Mesh::operator[];
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
