# fast-DBSCAN

## 1. Introduction
Cython package for accelerated DBSCAN[1]
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


## 3. Sequential Implementation
- code: sequential.cpp  
Basic implementaion of DBSCAN using only a single CPU.  

## 4. Parallel Implementation with Multi-CPU
TODO

## 5. Parallel Implementation with GPU
TODO


### Reference
[1] Ester, Martin; Kriegel, Hans-Peter; Sander, Jörg; Xu, Xiaowei (1996). Simoudis, Evangelos; Han, Jiawei; Fayyad, Usama M. (eds.). A density-based algorithm for discovering clusters in large spatial databases with noise. Proceedings of the Second International Conference on Knowledge Discovery and Data Mining (KDD-96).
