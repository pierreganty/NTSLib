# NTSLib - a collection of Numerical Transition Systems (NTS) 

## ABP2NTS
 
They are boolean abstraction of asynchronous programs obtained from [SATABS](http://www.cprover.org/satabs/)
which were then converted to [NTS](http://nts.imag.fr/).  To make the NTS recursionless a bounded
index approximation was applied on the boolean abstracted asynchronous program.
The unbounded variables in the NTS encode the buffer of pending tasks.  Those
examples have been produced by an OCAML prototype implemented by Bishesh
Adhikari during an internship at the IMDEA Software Institute.


## RECURSIVE

They are underapproximations of asynchronous programs with integer variables
obtained by applying the [delay-bounded
scheduling](http://dx.doi.org/10.1145/1926385.1926432) underpproximation of
Emmi, Qadeer and Rakamaric which returns a recursive sequential programs over
integer variables. The input programs are defined in the
[boogie](http://research.microsoft.com/en-us/projects/boogie/) language whereas
the ouput programs are defined as [NTS](http://nts.imag.fr/).  We adapted the
tool [c2s](https://github.com/pierreganty/c2s) of Michael Emmi to ouput the NTS
programs. Those recursive sequential NTS programs are located in the `dbseq/x.y/` directory.
Because some tools do not handle recursion we further applied an [index-bounded
underapproximation](http://dx.doi.org/10.1007/978-3-642-36742-7_18) on these
programs. The resulting recursionless sequential NTS programs are located in
the `x.y/z` subdirectories.
