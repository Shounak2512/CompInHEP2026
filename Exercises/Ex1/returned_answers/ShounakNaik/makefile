# use wildcard to collect inputs
SRC := $(wildcard *.tex)         
BIBSRC := $(wildcard *.bib)     
OBJECTS = $(basename $(SRC))


# compiling and cleaning
all: 
	$(MAKE) compile
	$(MAKE) clean

compile:
	pdflatex $(SRC)
	biber $(OBJECTS)
	pdflatex $(SRC)
	pdflatex $(SRC)

open:
	okular $(OBJECTS).pdf

clean:
	rm *.aux *.log *.bcf *.run.xml *.bbl *.blg

reset:
	rm *.aux *.log *.bcf *.run.xml *.bbl *.blg *.pdf