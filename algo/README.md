Kth Order Statistoc Algorithm 

This implemenatation works as nth_element in STL library.

Install Google Test to build tests:

sudo apt-get install libpthread-workqueue0 libgtest-dev

cd /usr/src/gtest
sudo cmake .
sudo make

ln -s libgtest.a /usr/lib/libgtest.a
ln -s libgtest_main.a /usr/lib/libgtest_main.a

To build project go to project's direcotry and run:
cmake .
make
make test

