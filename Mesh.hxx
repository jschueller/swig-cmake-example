#ifndef OPENTURNS_MESH_HXX
#define OPENTURNS_MESH_HXX

namespace OT {
  class Mesh
  {
  public:
    Mesh(const int nVert = 0) : nVertices_(nVert) {}
    int getNVertices() const {return nVertices_;}
  private:
    int nVertices_;
  };
}

#endif
