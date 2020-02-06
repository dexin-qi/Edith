# pip3 install breathe sphinx sphinx-autobuild sphinx_rtd_theme recommonmark sphinx-markdown-tables –user
rm -rf xml/*
doxygen Doxyfile
rm -rf build/*
sphinx-build -b html -d build/doctrees source build/html
