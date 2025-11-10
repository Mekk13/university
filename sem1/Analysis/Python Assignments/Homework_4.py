import math
import matplotlib.pyplot as plt
"""
sum from n=1 of (-1)^(n+1)/n = ln(2)
Maria Suciu <3
"""

def compute_partial_sum(n):
    partial_sum = 0
    for i in range(1,n+1):
        term=(-1)**(i+1) / i # we compute the term
        partial_sum+=term # we add it to the sum
    return partial_sum

def change_order_of_sum(n, p, q):
    #we are going to add p positive terms and q negative terms
    positive_elements = []
    negative_elements = []
    count_p=0
    count_q=0
    for i in range(1,n+1):
        term=(-1)**(i+1) / i # we compute the term
        if term <0 and count_q<q:
            negative_elements.append(term)
            count_q+=1
        elif term >0 and count_p<p:
            positive_elements.append(term)
            count_p+=1
    reordered_sum=sum(positive_elements)+sum(negative_elements)
    return reordered_sum


def main():
    n=1
    max_n=5000
    elements=[]
    different_n=[500,1000,3000,5000,10000]
    #different_n=[10,50,100,200]
    ln2 = math.log(2)

    #we create some lists to store the sums for plotting
    partial_sums_regular=[]
    partial_sums_reordered=[]


    for i in range(len(different_n)):
        partial_sum=compute_partial_sum(different_n[i])
        partial_sums_regular.append(partial_sum)
        print("Partial sum =",round(partial_sum,6), "Difference from ln(2): " , round(abs(partial_sum-ln2),6))

    print('\n')
    print("Enter the percentage of each type of element you wish to add (in respect to n):")
    p= int(input("positive numbers: "))
    q= int(input("negative numbers: "))

    for i in range(len(different_n)):
        partial_sum = change_order_of_sum(different_n[i],different_n[i]*(p/100),different_n[i]*(q/100))
        partial_sums_reordered.append(partial_sum)
        print("Partial sum =", round(partial_sum, 6), "Difference from ln(2): ", round(abs(partial_sum - ln2), 6))


    # plotting <3
    partial_sums_regular=list(map(float,partial_sums_regular))
    partial_sums_reordered=list(map(float,partial_sums_reordered))

    plt.plot(different_n,partial_sums_regular, label="Regular")
    plt.axhline(ln2, color="red", linestyle="--", label="ln(2)")
    plt.plot(different_n,partial_sums_reordered, label="Reordered")
    plt.legend()
    plt.ylabel('Partial sum')
    plt.xlabel('Number of elements')
    plt.show()

main()