swig cmake example
==================


.. image:: https://travis-ci.org/jschueller/swig-cmake-example.svg?branch=master
    :target: https://travis-ci.org/jschueller/swig-cmake-example

.. image:: https://ci.appveyor.com/api/projects/status/do7g9enyynbxf77h/branch/master?svg=true
    :target: https://ci.appveyor.com/project/jschueller/swig-cmake-example

demonstrates conda build bug on osx/python3 with default channel package

Usage
-----

::

    git clone https://github.com/jschueller/swig-cmake-example.git
    cd swig-cmake-example
    mkdir build && cd build
    cmake -DPYTHON_EXECUTABLE=/usr/bin/python3 -DCMAKE_INSTALL_PREFIX=$PWD/install ..
    make install VERBOSE=1
    PYTHONPATH=$PWD/install/lib/python3.6/site-packages python3 ../test-fieldfunction.py


Notes
-----
...
