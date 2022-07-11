#ifndef OPENTURNS_MESH_HXX
#define OPENTURNS_MESH_HXX
#include <vector>
#include <iostream>
#include <fstream>

namespace OT {
  class Mesh
  {
  public:
    typedef std::string FileName;

    Mesh(const int nVert = 0) : vertices_(nVert) {
      for (int i = 0; i< nVert; ++i)  
        vertices_[i]= 42.0+i;
    }
    virtual ~Mesh() {};
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

  virtual void __setitem__(int i, const double & val)
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

  void exportToTXT(const FileName & fn) const
  {
    std::ofstream dataFile(fn.c_str());
    dataFile << "size=" << getNVertices()<<std::endl;
    for (int i = 0; i < getNVertices(); ++i)
    {
      dataFile << vertices_[i] << std::endl;
    }
    dataFile.close();
  }

  void run()
  {
    int y = 0;
    while(true)
    {
      y+= 40;
    }
  }
  
  private:
    std::vector<double> vertices_;
  };
}

#endif
