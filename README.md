# Running the Original Implementation in Ubuntu
- Use eclipse on ubuntu and import the project from git; original URI: [https://github.com/miselico/globalRDFEmbeddingsISWC](https://github.com/miselico/globalRDFEmbeddingsISWC).
- Download Snap 3.0 from [http://snap.stanford.edu/snap/releases.html](http://snap.stanford.edu/snap/releases.html).
- Download Boost 1.63 from [https://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.gz/download](https://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.gz/download)
- Extract both projects (boost and snap).
- In eclipse: Go to Project (menu bar) -› Properties -› C/C++ General -› Paths and Symbols -› Add paths for the dependencies:
	- .../Snap-3.0/snap-core
	- .../Snap-3.0/snap-exp
	- .../Snap-3.0/snap-adv
	- .../Snap-3.0/glib-core
	- .../boost_1_63_0
- try to build the project by clicking on the hammer in eclipse
- Note that you have to delete directory debug always when the build fails and you changed something.

If this works, good. If not (error `No such file or directory: #include "base.h"`):
- Copy all contents of snap-core, snap-exp, snap-adv, glib-core into snap-core.
- In file `.cproject`, change the paths referring to cochez (lines 47 and 105) so that they point to the dependency files in your system environment.  

Try to build. If it works, good. If not (error `incomplete type struct __exception`):
- go to file .../Snap-3.0/snap-core/bd.cpp
- add in line 13 (right below line 12 stating `#elif defined(GLib_GLIBC) || defined(GLib_BSD)`) - [github issue #146](https://github.com/snap-stanford/snap/issues/146):
```C
struct __exception {
    int    type;      /* Exception type */
    char*  name;      /* Name of function causing exception */
    double arg1;      /* 1st argument to function */
    double arg2;      /* 2nd argument to function */
    double retval;    /* Function return value */
};
```

Try to build. If it works, good. If not (error: invalid conversion from char to const void):
- Fix the error directly in fl.cpp line 1157 by adding the explicit cast:
write(output, (const void*) '\0', 1);

Try to build, it if works, good. If not (error LoadSSPAr not declared):
- Fix the error directly in file table.cpp in line 765 by replacing the line with:
LoadSSSeq(T, S, InFNm, RelevantCols, Separator, HasTitleLine);

The build should work now. You should find a file RDFConverter in directory Debug.
	