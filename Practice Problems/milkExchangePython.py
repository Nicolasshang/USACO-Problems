N, M = map(int, input().split()) # number of cows and the number of minutes
S = list(input()) # The direction of each dow
A = [int(x) for x in input().split()] #this is the amount of milk each cow has
 
ans = sum(A)
 
for i in range(N):
    # The key observation to make is that a pair of "RL" cows will form a loop and just pass milk back and forth. However, if something like "RRL" occurs, then the middle cow will recieve two buckets of milk per minute, leading to an overflow.
    # If a string goes like "...RRRRL", then the amount of R's before that first R each contributes to +1 overflow. This is the only way any milk can be overflown.
    # Also note that capacity only matters when calculating the potential amount of milk given away (i.e. in a "RRR" or "LLL" chain).
    if (S[i] == 'R' and S[(i + 1) % N] == 'L'):
        # S[(i + 1) % N] is the item at the next index
        # (i - 1 + N) % N is the item at the previous index
        j = (i - 1 + N) % N
        total = 0

        # This runs everytime the letter before the 'R' in any 'RL' is another 'R.' 
        while S[j] == 'R':
            # Adding the amount of milk from every "R cow" cow before the first "R cow." Since each cow can only pass one liter per minute, it will take the same number of minutes to pass every liter of milk than these cows' combined capacity. 
            total += A[j]
            j = (j - 1 + N) % N 

        # min() is run here, because if the amount of minutes exceeds the capacity of the previous "R cows," the cows will run out of milk to pass before the time ends. If M is smaller, a total of M liters of milk will be passed to the first "R cow" and lost. 
        ans -= min(total, M)
    
    # Just do the exact same thing, but with the directions switched around
    if (S[i] == 'L' and S[(i - 1 + N) % N] == 'R'):
        j = (i + 1) % N 
        total = 0
 
        while S[j] == 'L':
            total += A[j]
            j = (j + 1) % N 
 
        ans -= min(total, M)
 
print(ans)