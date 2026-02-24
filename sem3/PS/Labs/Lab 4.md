# Continuous random variables 
Matlab: [abbr. of the distr. model] pdf/cdf inv. (where parameters compete, of the model)

Let X = a cont. rand. var.
cdf(x) = Fx(x) = P(X<=x) = integral from -inf to x of f(t)dt = P(X<x)
P(X=x) = 0 , for any x from R
 
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.11.17 - 2.23am.drawing",
	"width": 430,
	"aspectRatio": 1.5785148187416371
}
```
pdf(x) = f(x) (from the integral)
ex: P(a<X<b) = integral from a to b of f(t) dt = 
cdf(b) - cdf(a) 

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.11.17 - 2.25am.drawing",
	"width": 522,
	"aspectRatio": 1.2097835411431812
}
```

1. The average height of NBA professional basketball players is around 1.98 m, and the standard deviation is 8.8 cm. Assuming a Normal distribution of heights within this group, 
a) what percent of professional basketball players are taller than 2.1 m?
b) what is the probability that the height of a player is exactly 2.1 m? 
c) what proportion of professional basketball players are at least 2.1 m tall? 
d) what percentage of basketball players have heights between 1.9 and 2.2 m? 
e) estimate by simulations the probabilities above. 
f) if your favorite player is within the shortest 20% of all players, what can his height be? 
g) if your favorite player is within the tallest 15% of all players, what can his height be?  

Standard deviation = measurement of how far away are the heights from the avg. If it is 0, everyone is the same height. 

X from Niu(miu,sigma) 
Niu -> normal distr. 
miu -> average 
sigma -> st. dev.
X from Niu(1.9,0.088)

a) P(X> 2.1 m) = 1- P(X<=2.1) = 1-cdf(2.1)
1- normcdf(2.1,1.98,0.088) = approx 0.0863 = approx 8% 

b) P(X=2.1m) => in the continuous case the pdf is 0. So . We can't compute it in matlab . 
c) P(x>= 2.1m) => 1-P(X<= 2.1) = around 8%

# in continuous case theres no difference between >= and > or <= and <

d) P(1.9< X < 2.2) = cdf(2.2) - cdf(1.9) = Approx. 0.81 so 81%

e) rand from (0,1)  from U(0,1) ------> X from Niu(miu,sigma)
(convert to something normally distributed)

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.11.17 - 2.50am.drawing",
	"width": 484,
	"aspectRatio": 1.5898826292444672
}
```

# The Box - Muller transformation method :
If U1, U2 (rand) from U(0,1) .8 if:

Z1 = sqrt(-2lnU1) * cos (2xU2)
Z2 = sqrt(-2lnU1) * sin (2* x * U2)
Then  Z1, Z2 from Niu(0,1)

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.11.17 - 2.56am.drawing",
	"width": 516,
	"aspectRatio": 1.2530067982686748
}
```
Another transformation:

If Z from Niu(0,1), then X = sigma * Z + miu will be from Niu ( miu, sigma )

back to simulations:

N = the nr. of simulations
for i =1 : N 
	U = rand(1,2); % a vector with 2 random nrs
	z1 = sqrt(-2 * log(U(1)))* cos(2* pi * U(2))
	z2 = sqrt(-2 * log(U(1))) * sin (2 * pi * U(2))
end

sigma = 0.088, miu = 1. 98 
x = sigma * z1 + miu 

for a ) 
 ```
N = 10000;
sigma = 0.088;
miu = 1.98 ;
cnt = 0 ;

for i =1 : N 
	U = rand(1,2); % a vector with 2 random nrs
	z1 = sqrt(-2 * log(U(1)))* cos(2* pi * U(2));
	z2 = sqrt(-2 * log(U(1))) * sin (2 * pi * U(2));
    x = sigma * z1 + miu ;
    if x>2.1 
        cnt = cnt +1 ;
    end

end

freq = cnt / N 
 ```
for b) 
```
N = 10000;
sigma = 0.088;
miu = 1.98 ;
cnt = 0 ;

for i =1 : N 
	U = rand(1,2); % a vector with 2 random nrs
	z1 = sqrt(-2 * log(U(1)))* cos(2* pi * U(2));
	z2 = sqrt(-2 * log(U(1))) * sin (2 * pi * U(2));
    x = sigma * z1 + miu ;
    if x==2.1 
        cnt = cnt +1 ;
    end

end

freq = cnt / N 
```

c) 
```
N = 10000;
sigma = 0.088;
miu = 1.98 ;
cnt = 0 ;

for i =1 : N 
	U = rand(1,2); % a vector with 2 random nrs
	z1 = sqrt(-2 * log(U(1)))* cos(2* pi * U(2));
	z2 = sqrt(-2 * log(U(1))) * sin (2 * pi * U(2));
    x = sigma * z1 + miu ;
    if x>1.9 && x<2.1  
        cnt = cnt +1 ;
    end

end

freq = cnt / N 
```

# Quantiles 
 Until now we've had stuff like P( X < 2.1 ) = ? 
 Now, let's say that we have P(X < ? )  = 15% 
 This is the quantile of order 15% 
 P(X< ? ) = alpha , ? is the quantile of order alpha ,  denoted by  q alpha
 
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.11.17 - 3.28am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```
P( X < q alpha) = alpha <=> cdf(q alpha ) = alpha => q alpha = cdf power -1 of alpha 

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.11.17 - 3.29am.drawing",
	"width": 720,
	"aspectRatio": 4.453426943609021
}
```
For a game you can't directly enter probabilities you usually use the quantiles in the code. 

f) P(X < k ) = 20%
who is k??????????????

k  = norminv(0.2 , 1.98, 0.088) = 1.9059

g) P( X > k ) = 15% 
<=> 1 -  P (x <= k)  = 15% 
-> p(x<=k) =85 %
-> k = inv (0.25 ) = 2.07 m



2. The time it takes a printer to print a job is an Exponential random variable with the expectation of 12
 seconds.
 a) what is the probability that a document will take more than 30 seconds to be printed?
 b) if you send a job to the printer at 10 : 00 a.m. and it appears to be third in line, how likely is it that your document will be ready before 10 : 01?
 c) estimate by simulations the probabilities above

# Exponential model
X from Exp( lambda ) 
X -> models time
lambda -> the frequency of the rare event
lambda = 1/t 
t -> the average duration of a rare event

in matlab : Exp ( 1/ lambda )
so the parameter in matlab is just the time. 
# ! Don't write just the time in exams, only in matlab 

X from Exp( 1/12 sec power -1 ) 

a) P( X > 30 ) = 1 - expcdf(30 , 12) = approx 8%

b) X from Gamma(a, b)  multi stage process
X -> models time 
a-> number of stages (steps )
b-> avg. duration of a stage 

X from Gamma ( 3, 12 ) 
A document prints in 12 seconds, and the queue has 3 jobs 
in matlab it's gam not gamma

we want it to finish in 1 minute or less
P(  X < 60 )  = gamcdf(60,3,12) = approx. 87% 

c) simulation 
uniform -> exponential 
We need the
# Inverse Transform Method 
If U (rand) from U(0,1) , then :
X = -1/lambda * ln(U) from Exp (lambda )

This is homework. 


3. Estimate by simulations the number π = 3.1415926535...


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2025.11.17 - 3.52am.drawing",
	"width": 500,
	"aspectRatio": 0.9961390491918439
}
```
Nr. of points inside the circle / number of points inside square  = 
approx. Pi / 4


