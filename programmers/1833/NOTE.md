Non-DP O(N^2) solution:

- Sort points lexicographically: x[i]&lt;x[j] or (x[i]==x[j] and y[i]&lt;y[j]) for i&lt;j.
- Pick p_i as the left-side point of a the rectangle
- Choose j=i+1, i+2, ..., N-1. p_j will be the right-side point.
- If y[i]>y[j], for all k>j s.t. y[j]>y[k], x[i]&lt;x[j]&lt;x[k] and y[i]>y[j]>y[k], which means the rectangle determined by p_i, p_k contains p_j
- We can apply similar approach to y[i]&lt;y[j] case.
- Exclude all such rectangles from (p_i, p_k).
