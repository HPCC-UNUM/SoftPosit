SoftPosit - C library

SoftPosit is a C library. The library has support for posit8, posit16, posit32 and a flexible posit type which can be of size from posit2 to posit32. The library has different 
functionalities which include arithmetic operation, comparison operators, right shift, left shift, + (unary), - (unary), abs, not, and, or, xor, square root, fused-multiply-add,
fused-dot-products with quire, square root, conversion of types from double to posit and vice versa, round to nearest integer, convert to 32 bit integer, convert to NaR 
(Not a Real), convert to binary and convert to Hexadecimal. SoftPosit-Python which is built on top of SoftPosit has also been developed by S.H.Leong (Cerlane) from NGA Team. 
The library is a python wrapper for the existing C library SoftPosit.

SoftPosit – R package

The SoftPosit package lets the user perform all the functionalities which are provided in the existing SoftPosit C library with C++ support developed by S.H.Leong (Cerlane)
from NGA Team, and simplifies the task by helping the user to get rid of working with complex C syntax.

Getting Started

You would type the following command in R studio console   to download package from github 
Install_github(“hpcc-ncbc/SoftPosit”)

Prerequisites
You need to install the following libraries before using this package.
•	Crayon
•	binaryLogic
You would type the following command in R studio console   to download package:
install.package("Crayon")
install.package("binaryLogic")

Built With

SWIG  -  Simplified Wrapper Interface Generator, software tool used to connect library SoftPosit    written in C with scripting language R. 

Authors

Mahnoor Malik
