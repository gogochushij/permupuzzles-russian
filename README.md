# permupuzzles-russian
![](https://i.ytimg.com/vi/ciNiUuRvmbk/maxresdefault.jpg)
(Copyright hr-fernsehen)

The picture is a still from German quiz-show "wer weiss es?". The rules of this puzzle (presented in the final round of the show) are the following: the first 3-letter word is given, and each next word must be a permutation of the previous word plus exactly one new letter (ach -> a**u**ch -> **l**auch -> **s**chlau).

Here is a generator of such puzzles. It uses a dictionary and generates a puzzle like the above.

# How to use:

1. Find a dictionary. It must be **in txt format** and in **UTF-8** encoding. Anything that isn't exactly cyrillic words (this includes english words, russian words with hyphens) will be ignored. 

You may use [A.A. Zaliznyak's dictionary](http://www.speakrus.ru/dict/zdb-win.zip) (you must **convert** it to UTF-8!). Place the txt-file in the same folder as the program and **rename** the txt-file to "dict.txt". 

2. Compile the .cpp file (use no specific options). 

3. Create a text file "in.txt" in the same folder as the program. Write the following parameters in this file: 1) how many words you need, 2) word to start from 3) words you do not want in the chain (if any). Delimit the parameters with spaces or newlines. 

For example, the file
```
6 мир мирза мира
```
would lead to a chain of 6 words which starts from `мир` and does not contain `мирза` and `мира`.

4. Run the program. The file "out.txt" will be created, where you will see the generated chain. Note that for each "link" of the chain the program outputs all permutations of a found word which are also words (e.g. `кот`, `кто` and `ток`).
