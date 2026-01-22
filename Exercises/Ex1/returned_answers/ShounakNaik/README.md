Instructions to compile and clean

make ==compiles and cleans the folder of all temp files leaving behind the source and pdf files.

make reset ==along with the temp files it also deletes the pdf.

make open ==opens the pdf generated using okular pdf viewer

### IMPORTANT NOTE: I HAVE CHOSEN TO USE THE tikz-feynmann PACKAGE INSTEAD OF feynmf SINCE I HAVE USED IT BEFORE AND THE EXERCISE WAS TO CREATE A WORKING MAKEFILE  ###

Installation instructions (if necessary):

cd ~/Downloads
git clone https://github.com/JP-Ellis/tikz-feynman.git
cd tikz-feynman
mkdir -p ~/texmf/tex/latex/
cp tikz-feynman.sty ~/texmf/tex/latex/
mktexlsr ~/texmf

Test whether the package has successfully been installed:
kpsewhich tikz-feynman.sty
