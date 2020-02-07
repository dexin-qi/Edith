if [ -d "./xml" ];then
    echo "remove doxygen xml folder"
    rm -rf xml
fi
doxygen Edith.doxyfile

if [ -d "./build" ];then
    echo "remove sphinx build folder"
    rm -rf build
fi
sphinx-build -b html -d build/doctrees source build/html
