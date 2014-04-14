
#### 20140413

- Loading the program will load these objects/libraries as well, and perform a final linking.
- Often-used libraries ...
- A program, together with the libraries it uses, ...
- as the name implies
- In later releases of OS/360 and in subsequent systems, load-modules contained additional data about versions of components modules, to create a traceable record of updates.

#### 20140412

- Computer programs typically comprise several parts or modules; these parts/modules need not all be contained within a single object file, and in such case refer to each other by means of symbols. 
- Since a compiler seldom knows where an object will reside, it often assumes a fixed base location. 
- Additionally, in some operating systems the same program handles both the jobs of linking and loading a program.
- This approach offers two advantages. There are also disadvantages.
- If a bug in a library function is corrected by replacing the library, all programs using it dynamically will benefit from the correction after restarting them. Programs that included this function by static linking would have to be re-linked first.