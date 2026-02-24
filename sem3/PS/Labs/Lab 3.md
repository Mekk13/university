Bernoulli Distr. Model X c Bern(p) <- prob. of success

$$X(
\begin{array}{cc}
0 &1 \\
1-p &p
\end{array})
$$
Binomial distr. Model X c Bino(n,p) (nr trials, probability)
X denotes the nr of successes.
P( X = k ) = pdf ( k )
in Matlab :  [ abbreviated name of the model ] pdf (where to compute, params. )
ex: binopdf(  k, n, p)
ex: binopdf( 2,3,0.5)

P( x <= k ) = sum from i = 0 to k  of P(x = i)
command: cdf(k) -> same as pdf 

P(X>k) = 1- P(x>k) negated = 1-P(x<=k) = 1- cdf(k)

P(x<k) = P(x <= k-1) 
Method 1: = cdf ( k-1 )
Method 2: =cdf(k) - pdf ( k )

P(a< X <= b) = cdf (b) - cdf(a)

1) A student takes a multiple-choice test consisting of 20 questions. There are 4 answers to choose from for each question and only one is correct. If he randomly guesses every answer, find the probability that:
   
   a) he gets exactly 8 correct answers; 
   P(x=8) = pdf(8) = binopdf(8,20,1/4);
   success : he answers a question correctly

   b) he gets at least 13 questions wrong; 
   success: he answers a question wrong.
   x c Bino(20, 3/4) 
   P(X>=13 )  = 1 - (X<13 )= 1- cdf(12)
   1-binocdf(12,20,3/4) = 0.89 
   
   c) he passes the exam (gets 50% correct answers);
   P( X>= 10 ) = 1 - cdf(9) = 0.0139
   
   d) he gets more than 7 right answers;
   P(X>7) = 1-cdf(7) = 0.1018
   
   e) he passes the exam, but does not get a maximum score;
   P( 10 <= X < 20 ) = cdf(19) - cdf(9)
   or cdf(19) - cdf(10)+pdf(10)
   = 0.0139 it is NOT equal to c) , it's a rounding error in Matlab 
   
   f) he passes the exam, given that he answered at least 3 questions correctly
   conditional probability: P(A/B) = P(A intersected B ) / P(B)
   F = P(x>=10 | x >=3 ) = P(x>=10)/P(x>=3) = 1-cdf(9) / 1- cdf(2) = 0.0153
2) One year, 1000 high-school graduates take an exam for admission at the Faculty of Mathematics and Computer Science. Seven hundred of them take the exam in CS, the rest in Math. What is the probability that in 200 randomly selected students,
	a) 50 take the exam in Math;
	Hypergeometric distr. model
	 x c Hyge(N,n1,n) - pop size, pop size with charact., nr of trials
	 x c Hyge (1000,300,200) P(x=50) = pdf(50) = hygepdf(50,1000,300,200) = 1%

	b) at least 150 take it in CS.
	 desired charact. is taking examin CS . X c Hyge(1000, 700, 200)
	 P(X>=150) = 1- cdf(149) => 1 - hygecdf(149,1000,700,200) = 0.0493

3) A search engine goes through a list of sites looking for a given key phrase. The probability that any given site contains that phrase is 0.3 and the search terminates as soon as the key phrase is found. 
	a) find the probability that the search stops at the 5th site visited; 
	 Geometric distr. model . 
	 x - the nr of failures before the first success. 
	 x c Geo(0.3)
	 P(x = 4 ) = pdf(4)
	 geopdf(4,0.3) = 0.0720

	b) find the probability that the phrase is found after at most 3 sites; 
	 P(x<=3) with cdf = 0.7599
	 
	c) estimate by simulations the two probabilities in parts a) and b) 
	 rand c (0,1) , rand < 0.3 
	 a for loop repeating N times with a while loop repeating until the condition happens (break) 
	 then compare failures to 4, if its = then increase smth and make the frequency???
	
N = 1e5;

p = 0.3;

failures = zeros(1, N);

for i=1:N

x=0;

while rand >= p ;

x=x+1;

end

failures(i)=x;

end

P_a = sum(failures==4)/N

P_b = sum(failures<=3)/N