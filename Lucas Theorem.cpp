Lucas theorem is used to the value of nCr % p where p is a prime number and value of n,r is so big (10^18) that standard 
methods can't be used. First turn n and r to base p, and add leading zeros to r to make the two numbers length equal (if necessary).
Then calculate the binomial coefficients for each pair of corresponding base p digits. The answer is the product of the results mod p.
 
For example, here's how to calculate (472 C 86) % 5
 
Step 1: 472 in base 5 is 3342
	 86 in base 5 is 0321 (notice a leading zero is added)
 
Step 2: (3C0) % 5 = 1
	(3C3) % 5 = 1
	(4C2) % 5 = 6
	(2C1) % 5 = 2
 
Step 3: Multiply all the results -
	(1 * 1 * 6 * 2) % 5 = 12 % 5 = 2
 
Therefore (472 C 86) % 5 = 2 
