What is it from Markov Chain Monte Carlo (MCMC) algorithms that prevents us from parallelization process?

This was a question that stuburned me since I was first introduced by it in my Bachelors specialiazed in Statistical Physics for Ising Spin models.

The more I questioned the explanation, the much clearer it became to me that indeed it was parallelizable after all.

I will give the explanation based on my beloved Isig Model and all other models can be either developed analogous to or based from my structured algorithm.

# TL;DR

In other simpler words, we give up knowledge, to gain more knowledge.

# Parallelization = 0, Time = 0, N = 4, Geometry  = PBC1D
The minimal Graph based 1D model is:
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

to which, let us apply all possible Periodic Boundary Condition 1 Dimensional (PBC1D) symmetries:

$$\begin{aligned}
  \circ\circ\circ\circ&\uparrow\downarrow\uparrow\downarrow\\
  \circ\cdot\circ\cdot&\uparrow\downarrow\downarrow\uparrow\\
  \circ\circ\cdot\cdot&\uparrow\downarrow\uparrow\uparrow\\
  &\downarrow\uparrow\downarrow\downarrow\\
  \cdot\cdot\cdot\cdot&\uparrow\uparrow\uparrow\uparrow\\
  &\downarrow\downarrow\downarrow\downarrow
\end{aligned}$$

Please note that I will switch to ($\circ, \cdot$) notation to visualize the State of the Lattice. They represent the "presence" ($\circ:\uparrow\downarrow, \downarrow\uparrow$), or "absence" ($\cdot:\downarrow\downarrow, \uparrow\uparrow$) of an "interaction" between Spins and not the actual State of the $i^{\text{th}}$ spin ($s_i$).

We are mainly interested in the "interaction" sites since "race condition" phenomena would alter the evaluation of $s_i$'s "choice" leading to an unpredictable chaotic spiraling down black hole doom of the Universe... simulation.

Each spin has a well defined Objective function, which is to Minimize its hamiltonian (or "energy") via a well established Distribution function (Boltzman Distribution). None of them act "randomly", they act via well established probability distribution, regardless if it is a discontinious step or continuous smooth function. These are the Laws that govern in Quantum Mechanics. You really don't need to know which interaction is going on, you just need to know if an "interaction" occurs, there is n/(N - 1) probability that a race condition occurs, where n is the number of neighbors and N is the total Number of spins.

# Parallelization = 1, Time = $\Delta$, N = 4, Geometry  = PBC1D
Let us study the MCMC algorithm through a probabilitic prespective. Then we will limit our $\Delta$ to Zero and reach analog computing.

Let us simplify a few computations and focus on the hard ones. 1 core will randomly select an interaction ($\circ$). the probability that both select the same interaction is 1/I.

We know for a fact that the number of interactions (also known as 1D Domain Walls) decay in a power law, therefore the number of race conditions must grow asymptomatically to the number of spins.

Consider the following 2 independent self-centered workers which happen to intersect during their work (race condition interaction). Let's write their rules (DNA) and compute them at the 'same' and with a short offset.


$$
h(s_A) = -2\times s_A\times (s_L + s_B)\\
h(s_B) = -2\times s_B\times (s_A + s_R)\\
$$

If both strictly apply the rule of flip only to decrease, race condition no longer have effect on the simulation:

$$\begin{aligned}
\uparrow\downarrow\uparrow\uparrow
\uparrow\downarrow\uparrow&\downarrow\uparrow\uparrow
\uparrow\uparrow \?&\?\uparrow\uparrow
\uparrow\uparrow\uparrow\uparrow
\end{aligned}$$

if there was an offset in the computation of the state of the neighboring spin, then that would be the same as no parallelization process in which in any case, given the strict rules, end up in the same result by lowering the hamiltonian.

Consider:

$$\begin{aligned}
\uparrow\downarrow\uparrow\downarrow
\uparrow\downarrow\uparrow&\downarrow\uparrow\downarrow
\uparrow\uparrow \?&\?\uparrow\downarrow
\uparrow\uparrow\downarrow\downarrow
\end{aligned}$$

