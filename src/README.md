What is it from Markov Chain Monte Carlo (MCMC) algorithms that prevents us from parallelization process?

This was a question that stuburned me since I was first introduced by it in my Bachelors specialiazed in Statistical Physics for Ising Spin models.

The more I questioned the explanation, the much clearer it became to me that indeed it was parallelizable after all.

I will give the explanation based on my beloved Isig Model and all other models can be either developed analogous to or based from my structured algorithm.

# Parallelization = 0, Time = 0, N = 4, Geometry  = PBC
$$
\begin{aligned}
  \uparrow\uparrow\downarrow\downarrow\\
  \uparrow\downarrow\uparrow\downarrow\\
  \downarrow\uparrow\uparrow\downarrow\\
  \downarrow\uparrow\downarrow\uparrow\\
  \downarrow\downarrow\uparrow\uparrow\\
\end{aligned}
$$
to which, let us apply all possible PBC symmetries:
$$
\begin{aligned}
  \uparrow\uparrow\downarrow\downarrow\\
  \uparrow\downarrow\uparrow\downarrow\\
\end{aligned}
$$
Please note that I will keep the arrow notation to visualize the State of the Lattice. The arrows only represent the "presence" ($\uparrow$), or "absence" ($\downarrow$) of an "interaction" between Spins and not the actual State of the $i$th spin ($s_i$). It is convinient to explain it this was since there is a 1 to 1 correspondance to the States of the model and $N > 4$ would add a bit more confusion when dealing with Recursive Parallelization.
