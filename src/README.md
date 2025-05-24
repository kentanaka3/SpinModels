What is it from Markov Chain Monte Carlo (MCMC) algorithms that prevents us from parallelization process?

This was a question that stuburned me since I was first introduced by it in my Bachelors specialiazed in Statistical Physics for Ising Spin models.

The more I questioned the explanation, the much clearer it became to me that indeed it was parallelizable after all.

I will give the explanation based on my beloved Isig Model and all other models can be either developed analogous to or based from my structured algorithm.

# Parallelization = 0, Time = 0, N = 4, Geometry  = PBC

$$\begin{aligned}
  \uparrow\uparrow\uparrow\uparrow\\
  \downarrow\uparrow\uparrow\uparrow\\
  \uparrow\downarrow\uparrow\uparrow\\
  \uparrow\uparrow\downarrow\uparrow\\
  \uparrow\uparrow\uparrow\downarrow\\
  \uparrow\uparrow\downarrow\downarrow\\
  \uparrow\downarrow\uparrow\downarrow\\
  \downarrow\uparrow\uparrow\downarrow\\
  \downarrow\uparrow\downarrow\uparrow\\
  \downarrow\downarrow\uparrow\uparrow\\
  \downarrow\downarrow\downarrow\uparrow\\
  \downarrow\downarrow\uparrow\downarrow\\
  \downarrow\uparrow\downarrow\downarrow\\
  \uparrow\downarrow\downarrow\downarrow\\
  \downarrow\downarrow\downarrow\downarrow\\
\end{aligned}$$

to which, let us apply all possible Periodic Boundary Condition (PBC) symmetries:

$$\begin{aligned}
  \circ\circ\circ\circ&\uparrow\downarrow\uparrow\downarrow\\
  \circ\circ\cdot\cdot&\uparrow\downarrow\uparrow\uparrow\\
  &\downarrow\uparrow\downarrow\downarrow\\
  \cdot\cdot\cdot\cdot&\uparrow\uparrow\uparrow\uparrow\\
\end{aligned}$$

Please note that I will switch to ($\circ, \cdot$) notation to visualize the State of the Lattice. They represent the "presence" ($\circ:\uparrow\downarrow, \downarrow\uparrow$), or "absence" ($\cdot:\downarrow\downarrow, \uparrow\uparrow$) of an "interaction" between Spins and not the actual State of the $i^{\text{th}}$ spin ($s_i$).
