# fast-DBSCAN

## 1. Introduction
Cython package for DBSCAN accelerated via SYCL
![alt text](https://github.com/jhson989/fast-DBSCAN/blob/master/images/demo.png?raw=true)

## 2. How to Run
- Build
    1. mkdir build && cd build
    2. cmake ..
    3. make
    4. make install (You have to change the install path in the file "src/CMakeLists.txt" line 1)
- Test
    1. cd test
    2. python test.py


## 3. Sequential Version