#include <stdlib.h>
#include <stdio.h>

// 	Use Geometric progression.
// 	M + (N ^ (n-1)) = (1 - (N ^ n)) / (1 - N)
// 	Here (N ^ (n-1)) is the number of leaf-nodes. Solving for this leads to the answer
// 	Leaf nodes = M * (N - 1) + 1 Suppose you have a 3-ary tree
// 	A
// 	B	C	D
// 	E  F  G   H  I  J   K  L M
// 	So, here M=4 and N=3. So using the formula above, Leaf nodes = M * (N - 1) + 1 = 4 * (3 - 1) + 1 = 9