This is a randomized algorithm to check if product of 2 square matrix A and B is C. 


Input
Three n × n matrices A, B, and C.

Output
Yes, if A * B = C; No, otherwise.

Procedure

Repeat the following k times: 

    Generate an n × 1 random 0/1 matrix r.
    Compute P = (A * (B * r)) - (C * r)

    If there is a non-zero element in P, output "No" and exit;

If the program is not exited after k times, output "Yes" and exit;

Complexity: O(k*n*n)

Chances of failure after k iteration: 2^(-k)
