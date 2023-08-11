# SouthPacific2022
This is the editorial for ICPC divisonal last year (2022) (My version) 

Problem A : (Trivial)
Let A[i] be the boolean value for the ith column
Thus A[i] = 1 when column ith column has the same characters 
Hence, we know only need to find the longest substring of 1.
Time Complexity O(M * N)

Problem B: (Data structures, Inversions)
Observation, after each loops, the number of inversions of each element 
is going to reduce by 1 (as the larger element is shifting towards the end). 
Thus the number of pass is going to be the maximum number of inversions of
the elements.
Let L[k] = number of elements with k inversions 
Thus for round kth, the answer is L[k] + L[k + 1] + L[k + 2] + ... 
We can compute the number of inversions by compressing the value and store it 
in fenwick tree. 
Thus the time complexity is O(NLogN + M) where M is the maximum number of inversions of a single element

Problem C: (modified BFS)
Observe that N is large, so each time we are going to loop through the set of adjacent vertices, 
delete all the vertices that have already been visited. This will leave the number of vertices that
we have to travere become smaller and smaller. Using std :: set, the time complexity of this problems
is O(NlogN) 

Problem D: (Prime factorization)
Note that since N is large, we can not compute the Binominal normally (TLE and intergers overflow). 
Thus we need find for each primes, the number of times it appears in the prime factorization of 
numbers from (n - k + 1) ( n - k + 2) ... n && (k!). Knowing all these values, we know just do multiplication 
until the number large enough. 
Time Complexity : O(N * (M + K) * log(MAX)) where MAX is the maximum values appears in the set 

Problem E: (Efficient City)
Note that for the leftmost and rightmost house to be connected, there must be some cities between (let that be k) 
such that L[k] <= leftmost && rightmost <= house. Thus we can solve the subproblems for [leftmost, k - 1) && (k + 1, rightmost]
by knowing that houses from two intervals [leftmost, k] & [k, rightmost] can be connected to each other. 
Thus we would end up with some algorithms (going from leftmost to rightmost and check answer) 
which is pretty similar to Quicksort which ends up in O(N^2) worst case.
To speed up, we now going from both sides of the intervals. 
Time Complexity: O(NLogN) 

Problem F: (Floating Point)
Let f(xt) = |P1 - P2| where P1, P2 is two polygons created after the cut by line x = xt
We can easily observed that f(x) is a concave function.
Thus we only need to do ternary search to find the aprroximate value of xt
Now we are going to compute the value of P1, P2 for a fixed xt, 
The first thing we need to do is to cut the Polygon into the upper and lower part. 
and find the intersections of the line x = xt with these parts (use binary search to find 
the segment that covers the point xt). 
Then we can compute the area of P1, P2 by using shoelaces theorem. 
Note: To implement this problem easiers, i recommend rotating the polygon by 90 degrees. 
Time complexity: O(NLogN)

Problem G: (Knapsack)
This is just Knapsack problems 
Time Complexity : O(NK)

Problem H: (Trivial) 
Just do what the problem describe 
Time complexity: O(N * P * C)

Problem I: (2 - SAT)
This is just a version of 2-SAT problems, we can model first dish as x1 and second dish as negate(x1) 
Thus we only need to find assignment such that negate(x[i] and x[j]) is true. 
Time Complexity : O((m + n) * L) where L is length of the string  

Problem J: (Greedy)
Using greedy strategy, assign the "closest to the destination" children with the slowest speed that make that children 
able to escape the wolf. 
Time complexity: O(N ^ 2) 

Problem K: (Trivial)
Just do what the problem describe 
Note : to implement easier, you should flatten the board into an array 
Time complexity: O(N)

Problem L: (Tree Dp, Game)
First, let's fixed the starting point.
Observed that for a node to losing state only when all of its childrens always lead to the winning state (The leaf is 
a winning state since people can not make a move are now able to call ice cream). 
Thus we can easily compute that for fixed node 1 using a single DFS call, 
Now by doing re - root Dp, we are able to compute it for all nodes in the tree and get the answer.
Time Complexity: O(N) 
