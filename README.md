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

If this works, good. If not (error `No such file or directory: #include "base.h"`):
- Copy all contents of snap-core, snap-exp, snap-adv, glib-core into snap-core.
- 


	