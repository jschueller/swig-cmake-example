#ifndef OPENTURNS_MESH_HXX
#define OPENTURNS_MESH_HXX
#include <vector>
namespace OT {
  class Mesh
  {
  public:
    Mesh(const int nVert = 0) : vertices_(nVert) {
      for (int i = 0; i< nVert; ++i)  
        vertices_[i]= 42.0+i;
    }
    int getNVertices() const {return vertices_.size();}

    const double & operator [] (const int i) const
  {
    return vertices_.at(i);
  }
    
    double __getitem__(int i) const
    {
      if (i < 0)
      {
        i += getNVertices();
      }
      return vertices_.at(i);
    }
    
    virtual void __setitem__(int i,
                           const double & val)
  {
    if (i < 0)
    {
      i += vertices_.size();
    }
    vertices_.at(i) = val;
  }
    
    
    inline
  int __len__() const
  {
    return vertices_.size();
  }
    
  private:
    std::vector<double> vertices_;
  };
}

#endif
