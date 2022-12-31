# Book Information (Overriding Member Functions)

Given `main()` and a base `Book` class, define a derived class called `Encyclopedia`. Within the derived `Encyclopedia` class, define a `PrintInfo()` function that overrides the `Book` class' `PrintInfo()` function by printing not only the `title`, `author`, `publisher`, and `publicationDate`, but also the `edition` and `numVolumes`.

Ex. If the input is:

```cpp
The Hobbit
J. R. R. Tolkien
George Allen & Unwin
21 September 1937
The Illustrated Encyclopedia of the Universe
James W. Guthrie
Watson-Guptill
2001
2nd
1
```

the output is:

```cpp
Book Information:
Book Title: The Hobbit
Author: J. R. R. Tolkien
Publisher: George Allen & Unwin
Publication Date: 21 September 1937
Book Information:
Book Title: The Illustrated Encyclopedia of the Universe
Author: James W. Guthrie
Publisher: Watson-Guptill
Publication Date: 2001
Edition: 2nd
Number of Volumes: 1
```

Note: Indentations use 3 spaces.
