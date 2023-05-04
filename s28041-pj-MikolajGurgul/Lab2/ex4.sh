#!/bin/bash
ls -l
X=$(ls -l)
#echo $X dzieli zawartosc zmiennej X na slowa separowane spacjami i wyswietla kazde slowo oddzielnie,
#natomiast ls -l wyswietla kazdy plik lub katalog w jednej linii wraz z pelnymi informacjami na jego temat
#potrzebe jest wywolanie zmiennej z parametrem -e, ktore pozwala na interpretacje specjalnych znakow
#takich jak znaki nowej linii, znaki kontrolne oraz kolory
echo -e "$X"
