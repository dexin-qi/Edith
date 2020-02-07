if [ -d "./xml" ];then
    echo -e "\e[1;31mremove:\e[0m doxygen xml folder"
    rm -rf xml
fi
doxygen Edith.doxyfile

if [ -d "./build" ];then
    echo -e "\e[1;31mremove:\e[0m sphinx build folder"
    rm -rf build
fi
sphinx-build -b html -d build/doctrees source build/html

echo -e "\e[1;38mdocygen doc build\e[0m \e[1;32msuccess\e[0m"
