.PHONY: all clean

all: flexc++.pdf flexc++.html

clean:
	rm flexc++*.html flexc++.{aux,latex,log,pdf,toc}

flexc++.html: *.yo
	yodl2html flexc++

flexc++.pdf: *.yo
	yodl2latex flexc++
	pdflatex flexc++.latex
	pdflatex flexc++.latex
