http://en.wikibooks.org/wiki/Python_Programming/Extending_with_C
http://docs.python.org/extending/extending.html
http://docs.python.org/extending/building.html#building
http://docs.python.org/install/index.html

python setup.py build
####Deprecated: python setup.py install --home=$HOME/python
# Install method 1 installs your libs into $HOME/.local/lib/python3.12/site-packages
# use correct path in the test script
pip install --user . --break-system-packages

# Install method 2: use your own custom dir. This is 'cleaner' as you dont need the option --break-system-packages
# use correct path in the test script
pip install . --target=$HOME/python
