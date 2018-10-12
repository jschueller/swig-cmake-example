#ifndef OPENTURNS_FIELDFUNCTIONIMPLEMENTATION_HXX
#define OPENTURNS_FIELDFUNCTIONIMPLEMENTATION_HXX

#include "Mesh.hxx"

namespace OT {
  class FieldFunctionImplementation
  {
  public:
    FieldFunctionImplementation() {}
  protected:
    Mesh inputMesh_;
  };
}

#endif
