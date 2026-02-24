Descriptive Statistics. Correlation & Regression.

1.  The numbers of blocked intrusion attempts on each day, during the first two weeks of the month, on some site, were 56, 47, 49, 37, 38, 60, 50, 43, 43, 59, 50, 56, 54, 58. After the change of firewall settings, the numbers of blocked intrusions during the next 20 days were 53, 21, 32, 49, 45, 38, 44, 33, 32, 43, 53, 46, 36, 48, 39, 35, 37, 36, 39, 45. To compare the number of blocked intrusions before and after the change,
a) compute the minimum, maximum, mean, standard deviation, quartiles and interquartile range, for the two sets of data; 
b) construct histograms (with 10 classes), one on top of the other; 
c) construct side-by-side boxplots; Comment on your findings.


Quartiles:
prctile ( vector, [25 50 75])
 [25 50 75] -> percentages. They signify 25% of your data is below the result , 50% etc.


The interquartile range:
iqr( vector ) = Q3 - Q1 (from quartiles)

Histograms:
histogram(vector, the nr. of classes)
for the 'before' :
![[Pasted image 20251215024931.png]]

Boxplots:
subplot - to divide plots into 2 parts 
subplot( 1, 2, 1); -> 1 row, 2 columns, draw first in figure 1 
subplot( 1, 2, 2);

boxplot( vector , 'Labels' , 'before')
boxplot(vector , 'Labels', 'after')

![[Pasted image 20251215025648.png]]
--- | are the min and max non-outliers ( min - down, max - up)
(whiskers)

min non-outlier = Q1 - 1.5 *  IQR
max non-outlier = Q3 + 1.5 *  IQR

![[Pasted image 20251215031246.png]]
So clearly we would be better off if we switched the firewall before and after vectors - as more attempts are blocked in our current 'before' . 

```
before = [56, 47, 49, 37, 38, 60, 50, 43, 43, 59, 50, 56, 54, 58];

after = [53, 21, 32, 49, 45, 38, 44, 33, 32, 43, 53, 46, 36, 48, 39, 35, 37, 36, 39, 45];

min(before);

min(after);

max(before);

max(after);

mean(before);

mean(after);

std(before); % standard deviation

std(after);

prctile(before,[25 50 75]); % quartilles

prctile(after, [25 50 75]);

iqr(before) ;

iqr(after) ;

histogram(before , 10 );

subplot( 1, 2, 1); boxplot(before , 'Labels' , 'before') ;

subplot( 1, 2, 2); boxplot(after , 'Labels', 'after') ;

% transform our row vectors to column vector by transposing :

alldata = [before' ; after'] ;

%command to repeat stuff - for labels in this case:

before_labels = repmat({'before'}, size(before) );

after_labels = repmat({'after'}, size(after) );

all_labels = [before_labels' ; after_labels'];

figure

boxplot(alldata, all_labels)
```


2. The following data set represents the number of new computer accounts registered during ten consecutive days, by some online service provider company. 43, 37, 50, 51, 58, 105, 52, 45, 45, 10. a) Compute the mean, median, quartiles and standard deviation. b) Construct the boxplot and check for outliers using the 3/2 (IQR) rule. c) Remove the detected outliers and compute the mean, median, quartiles and standard deviation again. What conclusion can be drawn about the effect of outliers on basic descriptive statistics?

![[Pasted image 20251215033201.png]]

outliers:
isoutlier (vector, 'quartiles')
ans =  
1×10 [logical](matlab:helpPopup\('logical'\)) array  
0 0 0 0 0 1 0 0 0 1

V= isoutlier(acc,'quartiles') ;
vector(V)
-> shows the actual outliers from the vector.

```
acc = [43, 37, 50, 51, 58, 105, 52, 45, 45, 10];

mean(acc);

median(acc);

std(acc);

prctile(acc, [25 50 75]);

%median is also the second quartile.

boxplot(acc, 'Labels', 'accounts');

V= isoutlier(acc,'quartiles') ;

acc(V);

new_accounts = acc ( V == 0 );

mean(new_accounts)

median(new_accounts)

std(new_accounts)

prctile(new_accounts, [25 50 75])
```

3. The data below represent investments, in 1000 EUR’s, in the development of new software by some small computer company over an 11-year period. Year, X 2014 2015 2016 2017 2018 2019 2020 2021 2022 2023 2024 Investment, Y 17 23 31 29 33 39 39 a) Compute the means and variances of the two sets of data; b) Compute the covariance and the correlation coefficient of X and Y ; 40 41 44 47 c) Draw the scatter plot, fit a linear regression model and use it to predict the amount invested in 2026
covariants:
cov(x,y) = ( ) a matrix.
on the first diagonal you get the var of the x,y ,  second diagonal you get covxy

covXY = CovM

corrcoef(year,inv) 
-> its divided by the matrix -> first diagonal is 1
and second is fxx

![[Pasted image 20251215035208.png]]
with lsline:
![[Pasted image 20251215035319.png]]


```
year = [2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024];

inv = [17, 23, 31, 29, 33, 39, 39, 40, 41, 44, 47];

mean(year);

mean(inv);

var(year);

var(inv);

CovM = cov(year,inv);

covxy = CovM(1,2);

CorrM = corrcoef(year,inv) ;

rhoxy = CorrM(1,2) ;

scatter(year, inv, "r*");

lsline;
```