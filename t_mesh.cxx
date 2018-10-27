#include "Mesh.hxx"
#include <iostream>
using namespace OT;

int main()
{
//   Mesh mesh(4);
  std::vector<double> mesh(3);
  try {
    double v = mesh.at(8);
    std::cout << "v=" << v << std::endl; 
  }
  catch(std::out_of_range & ex)
  {
    std::cout << "CAUGHT out_of_range="<<ex.what() << std::endl; 
  }
  catch(std::exception & ex)
  {
    std::cout << "CAUGHT exception="<<ex.what() << std::endl; 
  }
  catch(...)
  {
    std::cout << "CAUGHT ?? =" << std::endl; 
  }
   std::cout << "OK" << std::endl; 
  
  
  return 0;
}
