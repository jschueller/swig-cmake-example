#ifndef OPENTURNS_DESCRIPTION_HXX
#define OPENTURNS_DESCRIPTION_HXX
#include <vector>
#include <iostream>
#include <fstream>

namespace OT {
  class Description
  {
  public:

    explicit Description(const int nVert = 0, const std::string & value = "") : coll_(nVert, value) {
    }
    virtual ~Description() {};
    int getSize() const {return coll_.size();}

  std::string operator [] (const int i) const
  {
    return coll_.at(i);
  }

  std::string & operator [] (const int i)
  {
    return coll_.at(i);
  }

  int __len__() const
  {
    return coll_.size();
  }

    std::string __repr__() const
    {
      std::string res("[");
      for (int i=0; i < getSize(); ++ i)
        res += coll_[i] + ",";
      res += "]";
      return res;
    }

    std::string __str__() const
    {
      return __repr__();
    }


  private:
    std::vector<std::string> coll_;
  };
}

#endif
