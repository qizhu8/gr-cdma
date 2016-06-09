#!/bin/bash
# by Yu Wang
# last modification Jun-09-2016

echo "i/install for compiling and installing"
echo "u/uninstall for uninstalling"
echo "r/reinstall for uninstalling and reinstalling"
echo "c/clean for cleaning this directory"

read cmd
if [ $cmd == "i" ] || [ $cmd == "install" ]; then
	sudo cmake -DENABLE_DOXYGEN=ON ../
	sudo make
	sudo make install
	sudo ldconfig
elif [ $cmd == "u" ] || [ $cmd == "uninstall" ]; then
	sudo make uninstall
elif [ $cmd == "r" ] || [ $cmd == "reinstall" ]; then
	sudo make uninstall
	sudo make clean
	sudo cmake -DENABLE_DOXYGEN=ON ../
	sudo make
	sudo make install
	sudo ldconfig
elif [ $cmd == "c" ] || [ $cmd == "clean" ]; then
	sudo rm -rf apps/ lib/ grc/ python/ include/ CMakeFiles/ docs/ swig/
	sudo rm cmake_install.cmake get_swig_deps.py cmake_uninstall.cmake Makefile CMakeCache.txt CTestTestfile.cmake install_manifest.txt python_compile_helper.py
fi
