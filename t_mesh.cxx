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
  catch(std::length_error & ex)
  {
    std::cout << "CAUGHT length_error="<<ex.what() << std::endl; 
  }
  catch(std::invalid_argument & ex)
  {
    std::cout << "CAUGHT   invalid_argument="<<ex.what() << std::endl; 
  }
  catch(std::domain_error & ex)
  {
    std::cout << "CAUGHT   domain_error="<<ex.what() << std::endl; 
  }
  catch(std::logic_error & ex)
  {
    std::cout << "CAUGHT logic_error="<<ex.what() << std::endl; 
  }
  catch(std::range_error & ex)
  {
    std::cout << "CAUGHT   range_error="<<ex.what() << std::endl; 
  }
  catch(std:: overflow_error  & ex)
  {
    std::cout << "CAUGHT    overflow_error ="<<ex.what() << std::endl; 
  }
  catch(std::underflow_error  & ex)
  {
    std::cout << "CAUGHT   underflow_error ="<<ex.what() << std::endl; 
  }
  catch(std::runtime_error  & ex)
  {
    std::cout << "CAUGHT   runtime_error ="<<ex.what() << std::endl; 
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

  try {
    double v = mesh.at(8);
    std::cout << "v=" << v << std::endl; 
  }
  catch(std::out_of_range & ex)
  {
    std::cout << "CAUGHT out_of_range="<<ex.what() << std::endl; 
  }
  std::cout << "OK2" << std::endl; 
    
  return 0;
}
