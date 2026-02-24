recovery 9-11 lab 6 on friday online

# C.I. and test for the difference of means & ratio of variances

P(miu from (ThetaL , ThetaU)) = 95% , ThetaL = 170, ThetaU = 180 
95% = confidence level 
95% = 1- alpha = 5% -> significance level 
170 - 180 => confidence interval (C.I.) -> two-tailed

It can also be:
(-inf, ThetaU) -> left-tailed C.I.
(ThetaL, +inf) -> right-tailed C.I.



miu1 - miu2 > 0 <=> miu1 > miu2 -> right tailed test
	       < 0                  <            -> left tailed test
	       != 0                  !=          -> two tailed test

in matlab: ttest2 

if we don't care about means, but we care about valiances, we use a diff test:
sigma1 ^ 2/ sigma2 ^2 is > , < or != then 1 
(its like comparing sigma1 ^2 with sigma2 ^2)
in matlab : vartest2

when we want to use ttest2 we first need vartest2

# Problem 1:
Two friends who like to play a popular online game, debate which one of them is a better player. Player A says he is a stronger player because his average score is, in general, higher. However, player B replies that he is more stable, because the variability of his scores is lower. The actual scores of the two friends (presumably, independent and Normally distributed), recorded over one month, are given in the table below.
Player A       85 92 97 65 75 96
Player B       81 79 76 84 83 77 78 82 

a) At the 5% significance level, is there significant evidence to support player A’s claim? Find also the rejection regions. 
b) Is there significant evidence to support player B’s claim? Find also the rejection region. 
c) Construct a 90% confidence interval for the difference of population means. 
d) Find a 92% confidence interval for the ratio of population standard deviations

Player A's claim: "miuA > miuB"

H0 : miu1 - miu2 <= 0 
the null hypothesis - should always contain equality 
it is always opposite of H1 ->  its <=

H1: miu1 - miu2 > 0 
the alternative hypothesis 
its > because the claim is: "miuA > miuB"

E.g. if claim were "miuA >= miuB", then H0 would be >=0 and H1 < 

Because the alternative hypothesis is correct => player A's claim is correct
In the null hypothesis => player A's claim is wrong 

<mark style="background: #ADCCFFA6;">How do we decide which is the correct one? H0 or H1?</mark>

We always have this question: <mark style="background: #FFF3A3A6;">Do we reject H0?</mark>
- if yes -> H = 1 , we reject H0 , hence player A's claim is correct
- if not -> H = 0, we don't have sufficient data to reject H0 , so we do NOT reject H0. (never write H0 is correct.  But you can think it.) =>player A's claim is wrong 


We need to check if sigmaA^2 = sigmaB^ 2
H0: sigmaA^2 = sigmaB^2 Q: do we reject H0?
if yes: H=1 -> we reject H0 , the variances are !=
if not: H = 0 => the variances are = 
h1: sigmaA^2 != sigmaB^2 
-> two-tail test 

in matlab:
[H,P,CI,STATS] = vartest2(A,B,'alpha',0.05,'tail') -> if its a right-tail you write right, for left tail you write left and for 2 tail you actually do not write tail at all.

```
A= [85, 92, 97, 65, 75, 96];

B= [81, 79, 76, 84, 83, 77, 78, 82];

[H,P,CI,STATS] = vartest2(A,B,'alpha',0.05)

if H == 1

fprintf("We reject H0\n")

else

fprintf("We don't reject H0\n")

end
```

STATS.fstat = the observed value of the statistical test  = TS0
STATS.df1
STATS.df2

Method 2:
Significance testing:
```
if alpha >= p

fprintf("We reject H0\n")

else

fprintf("We don't reject H0\n")

end
```

Method 3:
y TS0 from RR we reject H0, otherwise if not from RR we don't reject H0.

RR = (-inf, $t_{\alpha/2}$ ) U ($t_{1-\alpha/2}$, + inf)
F(n1-1, n2-1)

$t_{\alpha /2}$ = finv(${\alpha/2}$, STATS.df1, STATS.df2).

a) 
[H,P,CI,STATS] = ttest2(A,B,'alpha',0.05,'tail','right','vartype','unequal');
```
% a) 

[h,p,ci,stats] = ttest2(A,B,'alpha',0.05,'tail','right','vartype','unequal');

% method 1:
if h == 1
    fprintf("We reject H0\n");
    fprintf("Player A's claim is correct");
else
    fprintf("We don't reject H0\n");
    fprintf("Player A's claim is wrong");
end

% method 2:

if alpha >= p 
    fprintf("We reject H0\n");
    fprintf("Player A's claim is correct");
else
    fprintf("We don't reject H0\n");
    fprintf("Player A's claim is wrong");
end

% method 3:

stats.tstat;
t = tinv(1-alpha,stats.df)
% RR = (t 1- alpha , + inf) approx (1.98, + inf) 

```

b) 
Player B's claim is that he has a lower valiance than player A:
    $\sigma_A^2$  >  $\sigma_B^2$  

H0: 
    $\sigma_A^2$  >  $\sigma_B^2$  

H1: 
    $\sigma_A^2$  >  $\sigma_B^2$  
right-tailed test 

[H,P,CI,STATS] = vartest2(A,B,'alpha',0.05,'tail','right').

if H = 1 -> we reject H0 => player B's claim is correct
if H = 0 -> we don't reject H0  => player B's claim is wrong

```

% b) 


[h1,p1,ci1,STATS1] = vartest2(A,B,'alpha',0.05,'Tail','right');


if h1 == 1
    fprintf("We reject H0\n");
    fprintf("Player B's claim is correct");
else
    fprintf("We don't reject H0\n");
    fprintf("Player B's claim is wrong");
end
```

```
A= [85, 92, 97, 65, 75, 96];
B= [81, 79, 76, 84, 83, 77, 78, 82];
alpha = 0.05;
[H,P,CI,STATS] = vartest2(A,B,'alpha',0.05)

if H == 1
    fprintf("We reject H0\n")
else
    fprintf("We don't reject H0\n")
end

if alpha >= P
    fprintf("We reject H0\n")
else
    fprintf("We don't reject H0\n")
end

STATS.fstat;
n1 = STATS.df1;
n2 = STATS.df2;

t1 = finv(alpha/2 ,n1,n2);
t2 = finv(1-alpha/2,n1,n2);

fprintf("RR = (-inf, %f) U (%f, +inf)\n",t1,t2);

% a) 

[h,p,ci,stats] = ttest2(A,B,'alpha',0.05,'tail','right','vartype','unequal');

% method 1:
if h == 1
    fprintf("We reject H0\n");
    fprintf("Player A's claim is correct");
else
    fprintf("We don't reject H0\n");
    fprintf("Player A's claim is wrong");
end

% method 2:

if alpha >= p 
    fprintf("We reject H0\n");
    fprintf("Player A's claim is correct");
else
    fprintf("We don't reject H0\n");
    fprintf("Player A's claim is wrong");
end

% method 3:

stats.tstat;
t = tinv(1-alpha,stats.df)
% RR = (t 1- alpha , + inf) approx (1.98, + inf) 
TS0 = stats.fstat;
fprintf("%f\n",TS0);
fprintf("RR = (-inf, %f) U (%f, +inf)\n", t1, t2);

fprointf("(%f , +inf)", 1-alpha)
% b) 


[h1,p1,ci1,STATS1] = vartest2(A,B,'alpha',0.05,'Tail','right');


if h1 == 1
    fprintf("We reject H0\n");
    fprintf("Player B's claim is correct");
else
    fprintf("We don't reject H0\n");
    fprintf("Player B's claim is wrong");
end

if slpha >= b
    fprintf("We reject H0\n");
    fprintf("Player B's claim is correct");
else
    fprintf("We don't reject H0\n");
    fprintf("Player B's claim is wrong");
end

s1= STATS1.tstat;
fprintf("%f\n",s1);
fprintf("RR = (%f, +inf)\n", t22);
n11 = STATS.df1;
n22 = STATS.df2;

t22 = finv(1-alpha,n11,n22);

```