# NTSLib - a collection of Numerical Transition Systems (NTS) 

## ABP2NTS
 
They are boolean abstraction of asynchronous programs obtained from SATABS which were then converted to NTS.
To make the NTS recursionless a bounded index approximation was applied on the boolean abstracted asynchronous program.
The unbounded variables in the NTS encode the buffer of pending tasks.
Those examples have been produced by an OCAML prototype implemented by Bishesh Adhikari during an internship at IMDEA.


## RECURSIVE

They are underapproximations of asynchronous programs with integer variables
obtained by applying the delay-bounded scheduling underpproximation of Emmi,
Qadeer and Rakamaric which returns a recursive sequential programs over integer
variables.  Then the index-bounded underapproximation is applied on that
sequential program. The asynchronous programs are defined a boogie programs.
The result of the index-bounded underapproximation is a NTS. 
