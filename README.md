# Spell-Checker

This spell checker takes in two text files, a dictionary and a file to be spell-checked. It will find incorrect words and make suggestions on how to fix them by adding/removing a letter or by swapping two letters. The spell checker is implemented using a vector, set, and unordered set. The runtimes for all of them are printed to the terminal, showing how the set and unordered set are much more efficient than the vector.

Compile and run with:
g++ spellcheck.cpp -std=c++11
./a.out

Enter c.txt for word file
Enter d.txt for dictionary file

Results from the three different implementations will appear in three files called suggestions1.txt, suggestions2.txt, and suggestions3.txt, and time results will appear in the terminal. You can add words to the dictionary file (d.txt) if you wish.
