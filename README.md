# Spin Models




## Introduction
Throughout history we can appreciate many renown physicists studying and 
proposing solutions in different areas such as Economics, Politics and 
Sociology. The mechanisms held to study these problems and the proposed 
solutions differ from the traditional approaches. Physicists have been studying
the collective behaviour of human beings, as some of these phenomena resembles 
some of the physics models. We are not interested in the details of each 
individual behaviour rather the collective behaviour of the society as a whole, 
i.e. as the law of large numbers averages out the individual fluctuations and 
makes the general trend clearer. It is certain these simplistic models describe 
grossly the *fundamental* mechanisms which span over a wide range of 
phenomena. A few examples of such models in the field of Opinion Dynamics are 
the Ising Model [link](Ising_1925), Voter Model [link](Liggett), Sznajd Model 
[link](SZNAJD_WERON_2000), and several others.
[link](Castellano_2009, stauffer_2009).

One of the most interesting phenomena in society is racial segregation. This 
issue is of great importance due to the effects which can produce in future 
generations. Education, job opportunities, even marginalization, are some of 
the inequalities which can arise as consequence of racial segregation. This 
research aims to provide the reader the efforts previously given by several 
authors and the implementation of a recent physical model which may describe 
the evolution of racial segregation.

### Research Objectives
The main focus is to study the segregation process under the novel domain size 
dependent global spin exchange dynamics in a one dimensional Ising Spin system 
by studying both local and global conserved spin exchange dynamics. There are 
several well known models in local and global spin exchange dynamics that serve 
as our basis to further understand a segregation process in an Ising spin 
system.

First off all, we study the local spin exchange dynamics in the presence of 
temperature like noise as it reaches the ground state. Furthermore, the applied 
temperature like noise can be interpreted as an external influence applied upon 
the system, which we would like to study for a novel dynamics such as the 
domain size dependent global spin exchange.

On the other hand, we study the global spin exchange dynamics with different 
neighbourhood ranges in order to further develop our understanding of 
increasing the influence provided to a particular spin. As the segregation 
process occurs, the neighbourhood to consider will grow and we would like to 
have a comparable scheme which enables us to derive conclusions.

The domain size dependent spin exchange dynamics have been introduced in 
[link](Biswas_2009}) for studying the dynamics with the spin flips. This research 
takes place for studying the dynamics with spin exchange. We study several 
critical dynamical properties for a segregation process in a one dimensional 
Ising Spin system.

## Theoretical Framework
The one dimensional Ising Spin system [link](Ising_1925) consists of a lattice 
with length $L$, filled with spins at each site ($s$). The spins are referred 
in physics to the quantum-mechanical magnetic moments. The initial 
configuration for studying the dynamics consists of having randomly 
distributed, on average, half of the spins in one state, and the remaining half 
of spins in another state. This means that a single spin could be in either 
states with probability $\frac{1}{2}$. In this thesis the state of a site of a 
lattice in a given time are presented visually with arrows and values as 
follows:

$$
  s(t) = \left\lbrace\begin{aligned}
    \text{Spin up }&(\color{red}\uparrow\color{none}):& +1 \\
    \text{Spin down }&(\color{blue}\downarrow\color{none}):& -1
  \end{aligned}\right.
$$
\color{white}.\color{none}\\
Kyozi Kawasaki presented in 1966 a mechanism known as Kawasaki Dynamics 
[link](Kawasaki), as a description of the phase separation of a two-component 
alloy system into domains of pure metal. These models which preserve the global 
magnetization are known as *Magnetization Conserving Dynamics* 
[link](Leyvraz_1986). These *Conserved Dynamics* are based on the local 
ferromagnetic interaction between adjacent spins [link](Glauber_1963). The 
exchange procedure between spins in Kawasaki Dynamics are held locally 
(*i.e.* neighbouring or adjacent) and therefore it is known as Local 
spin exchange dynamics. Analogously, if the exchange procedure is between two 
non-adjacent spins then these models are known as Global spin exchange dynamics 
which was introduced by T. Schelling [link](Castellano_2009, Schelling_1971). We 
shall expand on these models in depth in the following section 
[\ref{def:exchange}].

### Definitions
The following set of definitions are used throughout the entire thesis and its 
extensiveness will be limited to the minimum for the purpose of describing the 
dynamical rules presented in this thesis.

#### Neighbourhood
A *neighbourhood* of a spin ($s_i$) is defined as all of the spins 
($s_j$) contained in a *section* of the lattice, *centered* at 
spin $s_i$. The size of the neighbourhood can vary depending on the interest of 
the dynamics. Given a dynamics the size of the neighbourhood does not refer to 
a fixed size, nor symmetric, as presented in Sec. \ref{def:SP}. A particular 
restrictive case of a neighbourhood is called as *domain*. A 
*domain* of spins refers to a cluster of neighbouring spins oriented in 
the same direction.

#### Quenching process
A *quenching* process is referred to a process where the temperature of 
a system is *instantaneously* reduced from a very high temperature, 
above the critical temperature ($T_C$), to a temperature below the critical 
temperature $(0 \leq T_f \ll T_C \ll T_i)$. For the particular case where the 
final temperature is reduced to absolute zero, the dynamics is called 
*zero temperature quenching* [link](NEWMAN2000159, Spirin_2001).

#### Early time effect
The early time effect refers to the regime with fluctuation for a few initial
time steps, previous to a power-law decay.

### Spin exchange dynamics
\label{def:exchange}
The conserved dynamics have also been studied in the context of racial 
segregation processes [link](Schelling_1971). Thomas Schelling presented a two 
dimensional model in which he argued (the popular beliefs) that racial 
segregation emerge naturally (*i.e.* without the need of an outside 
force such as political intervention) from the behaviour of citizens living 
in large cities. Schelling's model, relates in the basis of sociology to an 
exchange dynamics at the zero temperature [link](stauffer2007urban, 
MULLER_2008). A formal definition for the conserved global spin exchange 
dynamics in an Ising Spin system in one dimension, is provided as follows. Two 
spins are selected from the lattice at random as candidates to exchange sites 
(*e.g.* $s_i\Leftrightarrow s_j$), in a symmetric way depending on the 
interaction of the selected sites.

#### Local spin exchange dynamics
\label{def:local}
Kawasaki was particularly interested in representing a valid physical model and 
focused his attention to a local interaction of spins rather than the global 
interaction (Sec \ref{def:global}). In other words, in Kawasaki dynamics only 
neighbouring spins would exchange sites. Kawasaki defined a neighbourhood of 
fixed size (*window*: $w = 1$).
#### Global spin exchange dynamics
\label{def:global}
Schelling's two dimensional model can be described as a *global spin 
exchange dynamics* and could explain the formation of clusters, yet it fails to 
describe larger communities [link](Stauffer_2007}. Schelling reviewed (by hand) 
that the *unhappiness* of a citizen (*i.e.* spin) would be 
determined by its adjacent surrounding neighbours. Schelling defined an 
arbitrary fixed number called *tolerance* ($\tau\in\mathbb{R}[0, 1]$) 
which represent the threshold ratio between the satisfactory bonds 
(*i.e.* two spins share a state) and its neighbours. Schelling concluded 
that $\tau = 1/2$ segregated the community the most. An implementation of 
temperature like noise can be described in sociologists terms as the 
*tolerance* of the community [link](Stauffer_2007}. An *unhappy* 
citizen (in Schelling's model) is defined as being surrounded by opposing 
opinions, surpassing the $\tau$ threshold. Then, by simple common sense, this 
unhappy citizen would move to the *nearest* site which would satisfy its 
demands of *happines*. Schelling's proposed dynamical rule of exchanging 
sites, are deterministic rules, rather than probabilistic rules, despite the 
fact previous models had considered applying randomness. It is certain that the 
nearest neighbours have a larger weighted influence due to their proximity, 
however an entire community could play a role over the selected citizen, which 
introduces the basis of this research.
\vspace{-.4cm}
#### Global spin exchange dynamics under Social Pressure
\label{def:SP}
Social phenomena of segregation under Social Pressure has never been studied 
before by the physics community. This novel dynamics [link](Biswas_2009, 
Biswas_2011), uses the Ising Spin system to model the binary opinion dynamics. 
Social Pressure is modeled as a *domain size dependent dynamics*, 
(*i.e.* the entire neighbouring domain of spins takes part in the 
interaction with a selected spin). Considering the entire neighbouring domain, 
leads to a much more complex and rich dynamical behaviour. The domain of spins 
differs in its size from place and time. We interested in the segregation 
process of exchanging places binary spins in a lattice following the Social 
Pressure (i.e. domain size dependent global spin exchange dynamics). 

A visual representation of the interactions given in the dynamics of Social 
Pressure is presented as follows. The underlined *upwards* domain of 
spins and the underlined *downwards* domain of spins, interact with the 
spin ($\downarrow$) located in between these domains.
$$
  \ldots\color{blue}\downarrow\color{red}\uparrow\uparrow\uparrow
  \color{none}\color{none}\downarrow\color{blue}\downarrow
  \downarrow\color{none}\color{red}\uparrow\uparrow\color{none}\ldots
  \label{eq:SP}
$$

### Features of the spin exchange dynamics under quenching
Each dynamics under quenching process, comply to a set of rules and 
characteristics which will be discussed in this section. The local spin 
exchange dynamics allow us to better visualize the features, as well as 
simplify few computations of these features, however these are not only 
applicable to the local spin exchange dynamics and can go beyond.

#### Energy function
Each spin of the selected pair of spins measures its own local *energy 
function (Eq.\eqref{hamiltonian}) to minimize its energy. The energy function 
describes the interactions of the $i$th site spin within a given neighbourhood. 
The notation $\langle i,k\rangle$ in one dimension describes that for each $i$th 
site, $k$ represents the nearest left and right neighbours. For Kawasaki and 
Schelling model, the size of the neighbourhood is fixed to $w$. For the dynamics 
under Social Pressure the size of the neighbourhood is dependent on the nearest 
domain from spins of one of the selected spins.
$$
  \mathpzc{h}(s_i):=- s_i\sum_{\langle i,k \rangle}s_k
  \label{hamiltonian}
$$

The *energy* function is also equivalent to the *unhappiness* 
introduced by Schelling. Given the negative sign, denoted by convention, the 
objective of the $i$th site spin is to reduce the local energy function of 
itself by exchanging places with the $j$th site spin. Analogously the spin at 
the $j$th site would like to reduce its own local energy function. The local 
energy function is an additive function meaning that a local energy of two or 
more spins is simply the sum of the local energy of each spin. Hence we can 
conclude that for a finite size system, the \textbf{energy function} 
\eqref{hamiltonian2} of the entire system is simply the sum of all the local 
energy function of each spin.

$$
  \mathpzc{H}_t := \sum_{k = 0}^L \mathpzc{h}(s_k)
  \label{hamiltonian2}
$$

It is important to highlight that these spin exchange dynamics considers a 
probabilistical (Sec. \ref{def:delta_h}) reduction of both local energy 
functions of the selected candidate pair of spins as opposed to a purely 
selfish interest of each. The probabilistical framework are Glauber or 
Metropolis dynamics. For this particular study case, the spin exchange dynamics 
will be following the rule of Glauber Dynamics [link](Glauber_1963, 
Spirin_2001). The movement of spins to a lower energy state, we expect to 
eventually produce a segregated lattice with only two domains of spins.

#### Ground state
\label{def:ground_state}
The ground state refers to the minimal possible state of the system 
$(\mathpzc{H}_{\text{min}})$. Since the magnetization is conserved, it is clear 
to see that a minimal energy state is the state with only two domains of spins 
(*i.e.* completely segregated) $(\mathpzc{H}_{\text{min}} = 2w(4 - L))$. 
On the other hand, metastable states are characterized by spin domains of length 
two or longer. The number of such configurations in a system of length $L$ 
asymptotically grows as $g^L$, where $g = (1 + \sqrt{5})/2$ is the golden ratio 
[link](Krpvky).

#### Local finite energy difference
\label{def:delta_h}
Given the dynamical rule of exchanging sites, we define the local energy 
difference ($\Delta\mathpzc{h}_t$) between the current state 
$[\mathpzc{h}_t(s_i, s_j)]$ and the state after the proprosed spin exchanged 
$[\mathpzc{h}_{(t + 1)}(s_i, s_j)]$.
$$
  \Delta\mathpzc{h}_t = \mathpzc{h}_{t+1}(s_i, s_j) - \mathpzc{h}_t(s_i, s_j)
$$

For the specific case where the selected pair of spins are adjacent to each 
other and the neighbourhood is of fixed size (Local spin exchange dynamics) we 
can take advantage of the properties and simplify the local finite energy
difference $(\Delta\mathpzc{h}_t)$. Since clearly the selected candidate pair
of spins ($s_i$ and $s_{i + 1}$) are in each others range of the window $(w)$, 
they share $w - 1$ neighbours. Hence, by doing algebra, we are able to simplify 
the entire sumation and only consider the furthest neighbours as contributors 
to the local finite energy difference. Hence one can write the formula for 
$\Delta\mathpzc{h}_t$ as follows:
$$
  \Delta\mathpzc{h}_t = (s_i - s_{i + 1})(s_{i - w} - s_{i + 1 + w})
  \label{renorm}
$$
Despite the value of the window size $w$ only two spins (different from those 
who exchange) determine the outcome of the exchange. We can then, analyze the 
range of the local finite energy difference for the Local spin exchange 
dynamics, which results to $\Delta\mathpzc{h}_t\in 4[-1, 1]\in\mathbb{Z}$. 
Lastly, it is well known that due to the exchange of neighbouring spins, if no 
temperature like noise is applied to the system then the system will always 
reach one of the metastable states preventing it from reaching one of the 
*ground states* (Sec. \ref{def:transition_rates}, 
\ref{def:ground_state}).

#### Transition rates*
\label{def:transition_rates}
From the dynamical rule of spin exchange we can derive three types of movement: 
*Condensation*, *Evaporation*, and *Diffusion*.

Energy-lowering events, also known as *Condensation* process, occur when 
two anti-aligned spins exchange and at least one of them becomes part of their 
respective domain, extending the length of its domain of spins.

Energy-neutral events, also known as *Diffusion* process, occur when 
two anti-aligned spins exchange position without altering the energy of the 
system.

Energy-raising events, also known as *Evaporation* process, are opposite 
or inverse events of Condensation. This event makes at least one of the 
selected pair spins to break apart from their own domain of spins, reducing the 
length of the domain and increasing the overall energy of the entire lattice. 
These evaporation events go against the ultimate goal of reducing the energy 
function to the minimal. Therefore these events can be achieved only by applying 
a \textbf{temperature like noise} ($T$) onto the system. A graphical 
representation of these events held in the particular case where two 
neighbouring spins are selected to exchange sites with a window size $w = 1$, 
are shown as follows:

-  Condensation
$$
  \color{red}\uparrow\color{blue}\downarrow\color{red}\uparrow\color{blue}
  \downarrow\color{none}\quad\Rightarrow\quad\color{red}\uparrow\uparrow
  \color{blue}\downarrow\downarrow\color{none}\quad\&\quad\color{blue}
  \downarrow\color{red}\uparrow\color{blue}\downarrow\color{red}\uparrow
  \color{none}\quad\Rightarrow\quad\color{blue}\downarrow\downarrow
  \color{red}\uparrow\uparrow
$$
-  Diffusion
$$
  \color{blue}\downarrow\color{red}\uparrow\color{blue}\downarrow\downarrow
  \color{none}\quad\Leftrightarrow\quad\color{blue}\downarrow\downarrow
  \color{red}\uparrow\color{blue}\downarrow\color{none}\quad\&\quad
  \color{red}\uparrow\uparrow\color{blue}\downarrow\color{red}\uparrow
  \color{none}\quad\Leftrightarrow\quad\color{red}\uparrow\color{blue}
  \downarrow\color{red}\uparrow\uparrow\color{none}
$$
-  Evaporation
$$
  \color{blue}\downarrow\downarrow\color{red}\uparrow\uparrow\color{none}
  \quad\Rightarrow\quad\color{blue}\downarrow\color{red}\uparrow
  \color{blue}\downarrow\color{red}\uparrow\color{none}\quad\&\quad
  \color{red}\uparrow\uparrow\color{blue}\downarrow\downarrow\color{none}
  \quad\Rightarrow\quad\color{red}\uparrow\color{blue}\downarrow\color{red}
  \uparrow\color{blue}\downarrow
$$

##### $\pmb{T = 0}$
For a global spin exchange in one dimension with positve temperature, it has 
been reported that there is no phase transition $(T_C = 0)$, unlike two or 
three dimensions [link](Stauffer_2007) (*i.e.* the dynamics does not 
remain critical when temperature like noise is applied). Hence, critical 
dynamics is not expected for the application of temperature like noise onto the 
system, however the dynamical structure will still be analyzed. Specifically, in 
a zero temperature quenching process, only condensation and diffusion events are 
allowed Eq.\eqref{TR}.
$$
  \text{Zero temperature quenching process } (T = 0)\left\lbrace\begin{aligned}
    1 &: \text{Condensation rate}\\
    \frac{1}{2} &: \text{Diffusion rate}\\
  \end{aligned}\right.
  \label{TR}
$$

##### $\pmb{T > 0}$
It is clear that evaporation events must occur much more rarely than 
condensation events to reach the ground state. The rates of occurance of the 
different types of events can be calculated as follows. Following the detailed 
balance equation Eq.\eqref{eq:DBC}, $\omega_{1,2}$ is the transition rate from 
the current state to the proprosed exchange state and viceversa. 
$\mathpzc{p}_1$ and $\mathpzc{p}_2$ are the equilibrium probability of the 
current state and succeeding state, respectively. In equilibrium, both hold the 
Boltzman distribution.
$$
  \frac{\omega_{1,2}}{\omega_{2,1}} = \frac{\mathpzc{p}_{2}}{\mathpzc{p}_{1}}
  = e^{-\beta(\mathpzc{h}_{(t + 1)} - \mathpzc{h}_t)},\qquad \beta
  = \frac{1}{\kappa_{B}T}
  \label{eq:DBC} 
$$
$$
  \frac{\omega_{1,2}}{\omega_{2,1}} = \frac{1 - \gamma}{1 + \gamma}
  \quad\begin{cases}
    \omega_{2,1} = \frac{1 + \gamma}{2}\\
    \omega_{1,2} = \frac{1 - \gamma}{2}
  \end{cases},\quad\gamma 
  = s_i\tanh\left(\beta\sum_{\langle i,k\rangle}s_k\right)
$$
Hence, by doing algebra the transition rate for an energy-lowering event 
($\omega_{1,2}$, $\Delta\mathpzc{h}_t < 0$), can be reduced to an expression as 
follows:
$$
  \omega_{1,2} = \frac{e^{-\beta\Delta\mathpzc{h}_t}}
  {e^{-\beta\Delta\mathpzc{h}_t} + 1}, \qquad \Delta\mathpzc{h}_t < 0
  \label{eq:ADBC}
$$
The transition rate for a diffusive process is equal to $\frac{1}{2}$ since the 
energy function is not altered ($\Delta\mathpzc{h}_t = 0$) and it still 
satisfies the detailed balance condition. Therefore, the transition rates are 
presented as follows:
$$
  \left\lbrace\begin{aligned}
    \frac{e^{-\beta\Delta\mathpzc{h}_t}}{e^{-\beta\Delta\mathpzc{h}_t} + 1} &: 
    \text{Condensation rate }(\omega_{1,2})\\
    \frac{1}{2} &: \text{Diffusion rate}\\
    \frac{1}{e^{-\beta\Delta\mathpzc{h}_t} + 1} &: 
    \text{Evaporation rate }(\omega_{2,1})\\
  \end{aligned}\right.
  \label{eq:DBT}
$$

Evaporation events are of great importance in the one dimensional local spin 
exchange since these events prevent a system from being stuck into a metastable 
state. An evaporation event leads a spin to break apart from a domain, 
afterwards having the possibility to diffuse producing the coarsening of the 
system. Once the spin has split off, it follows the first-passage probability 
problem, this spin has a probability of $\frac{1}{l}$ o reach the domain located 
on the other side with a distance $l - 1$, meanwhile with probability 
$1 - \frac{1}{l}$ returns to its initial domain starting position of distance 1. 
Thus the probability that the $l$-domain hops by one step equals $\frac{1}{l}$, 
that is the diffusion coefficient of a domain equals the inverse of its length 
[link](Krpvky).

The transition rates have a direct dependancy on the local finite energy 
difference, which this in turn has a dependancy of the size of the domain 
(neighbourhood). From a socio-physics point of view, this could translate to a
quantifiable state of unhappiness which is not yet known to be measurable or 
even comparable with other citizens. In other words, as Schelling proposed in 
his model, an *unhappy* citizen is considered to be in the state of 
*unhappiness* regardless to the size of the neighbourhood (considering 
the possibility of being measurable), and therefore we study the dynamics under 
the temperature like noise only considering the sign of $\Delta\mathpzc{h}_t$ 
and not its value (*i.e.*, $|\Delta\mathpzc{h}_t| = 1$). As the Local 
spin exchange dynamics is restricted to the set of values \{-4, 0, 4\}, 
considering the non-unitary values of $\Delta\mathpzc{h}_t$ will only 
re-normalize the values of $\beta$ and will give the same dynamical structure as 
from Eq. \eqref{renorm}. Hence, the transition rates for are presented as 
follows:

$$
  \left\lbrace\begin{aligned}
    \frac{e^{-\beta}}{e^{-\beta} +1}&:\text{Condensation rate }(\omega_{1,2})\\
    \frac{1}{2} &: \text{Diffusion rate}\\
    \frac{1}{e^{-\beta} + 1} &: 
    \text{Evaporation rate }(\omega_{2,1})
  \end{aligned}\right.
  \label{eq:DBT2}
$$

Improvements can be done to this model such as extending it to two or three 
dimensions and review the previously studied sophisticated social environments 
or topologies on this framework. [link](Cortez_2015, Castellano_2009, 
Dall_Asta_2008) We numerically study different outcomes depending on the 
dynamics and variants.

Below in Fig. [\ref{fig:comparison}] we have explained the global spin exchange 
dynamics with a schematic figure. Two underlined spins from the lattice are 
selected to exchange sites. We present the Global spin exchange dynamics varying 
the window size and the Global spin exchange dynamics under Social Pressure.
\begin{figure}[H]
  \begin{gather*}
    L:\quad\color{red}\uparrow\color{blue}\downarrow
           \color{red}\uparrow\color{none}\color{blue}\downarrow
           \downarrow\color{none}\ldots\color{red}\uparrow\color{blue}\downarrow
           \color{blue}\downarrow\color{none}\color{red}\uparrow
           \uparrow\color{none}\quad\Rightarrow\quad\color{red}\uparrow
           \color{blue}\downarrow\color{blue}\downarrow\color{none}
           \downarrow\downarrow\color{none}\ldots\color{red}\uparrow\color{blue}
           \downarrow\color{red}\uparrow\color{none}\color{red}
           \uparrow\uparrow\\
    \text{Global spin exchange }\mathpzc{h}:\quad+2\ldots
                      0\Rightarrow
                      -2\ldots
                      0\rightarrow\text{Diffusion }(w = 1)\\
    \text{Global spin exchange }\mathpzc{h}:\quad+2\ldots
                      +2\Rightarrow
                      -2\ldots
                      -2\rightarrow\text{Condensation }(w = 2)\\
    \text{Social Pressure }\mathpzc{h}:\quad+3\ldots
                      +1\Rightarrow
                      -3\ldots
                      -1\rightarrow\text{Condensation}
  \end{gather*}
  \caption{Schematic comparison of the local energy between the fixed window 
           spin exchange dynamics with two different window sizes and the domain 
           size dependent spin exchange dynamics.}
  \label{fig:comparison}
\end{figure}


\begin{comment}
In contrast to the fixed window size spin exchange dynamics, diffusion process 
are probabilistically less likely to occur due to their neighbouring 
constraints. A symmetrical movement of a spin in between an anti-aligned odd 
size domain of spins with a neighbour is needed to occur for a diffusion 
process. A simple visual example of a scenario where a fixed window size 
conserved spin exchange dynamics $(w = [1,4])$ fullfils the criteria of a 
diffusion process is presented as follows. Meanwhile the notion of Social 
Pressure breaks the symmetry leading to a diffusion process occur less number 
of times. 
$$
  \ldots\color{red}\uparrow\color{blue}\downarrow\downarrow\downarrow\downarrow
  \color{red}\uparrow\color{blue}\downarrow\color{none}
  \color{blue}\downarrow\downarrow\downarrow\downarrow\downarrow
  \color{red}\uparrow\color{none}\ldots\quad\Rightarrow\quad\begin{cases}
    \mathpzc{h}_0 = 6\\
    \mathpzc{h}_f = 7
  \end{cases}\quad\Rightarrow\quad \Delta\mathpzc{h}_t = 1 > 0
  \label{eq:SPE}
$$
\end{comment}

## Methodology

- Magnetization (M): 


### Details and properties of the dynamics
The lattice which we have considered is an one dimensional array of size $L$ 
with periodic boundary conditions that visually represents a ring. Initially 
the spins are randomly distributed over the lattice by the Rademacher 
distribution (*i.e.* each spin could be in either states {-1, +1} with 
probability $\frac{1}{2}$). At every update, two *sites* of the lattice 
are selected (for the case of Local spin exchange dynamics, a single site and 
its neighbour is selected) at random (uniformly distributed over the lattice) 
and exchanged given the dynamical rule. $L$ of these updates are considered as a 
single Monte Carlo time-step (MCS). The total number of MCS ($t_{\text{max}}$) 
is fixed and decided depending on the size of the lattice. Since at every 
update, two sites are selected to exchange, at every MCS each site on average is 
selected twice. Every MCS and every update is dependent of the previous state. 
This represents a stochastic simulation. The simulation is run for 
$t_{\text{max}}$ and then repeated for $C$ number of different initial 
configurations. Since exchanging two sites with same value will not alter the 
energy function of the system, we disregard these cases and focus our attention 
only on those scenarios when two sites with different value are selected.

### Observables
Throughout the simulation we analyze or measure several properties of the 
system which we will call them observables. These dynamic properties are of our 
main interest due to the fact we can statistically predict the evolution of any 
system under the previously presented dynamics. Furthermore, depending on the 
behaviour we are able to increase the scale size of the system to reach the 
thermodynamic limit since our current computational resources for the 
simulations are not able to satisfy these demands.

#### Magnetization
The mean of the absolute value of Magnetization $(\mathcal{M}(t))$ refers to the average Magnetization 
($m(t)$) over different realizations (or initial configurations) at all time. 
The Magnetization refers to the overall orientation of the spins in the 
lattice. Since exchanging spins does not affect the magnetization, it should 
remain fixed as a constant throughout the entire simulation and is associated to 
each initial configuration. The Magnetization is computed to determine whether 
we are actually simulating conserved dynamics.
$$
  \begin{aligned}
    m(t)&=\left\langle s_i(t)\right\rangle_L\\
    &=\left\langle s_i(0)\right\rangle_L
  \end{aligned}\quad\forall t
\label{Magnetization}
$$

In a spin flip model [link](Ising_1925) the mean Magnetization is measured with 
the absolute value. The explanation is presented as follows. On average, half of 
the configurations, all spins will tend towards one direction while the other 
half will tend towards the other direction. In other words, by applying the 
absolute value to the magnetization we follow the measurments of a spin flip 
dynamic and we are able to differentiate between a spin flip dynamics and a spin 
exchange dynamics, as for spin exchange dynamics, the mean of the absolute value 
of magnetization shall remain fixed in time. Theoretically, at the thermodynamic 
limit, the mean of the absolute value of Magnetization should be exactly zero. 
However for the finite sample size, since the absolute value is taken before 
averaging over the configurations, it differs from zero. The mean of the 
absolute value of Magnetization is presented as follows:

$$
  \mathcal{M}(t)=\left\langle|\left\langle s_i(t)\right\rangle_L|\right
  \rangle_C\sim 0\quad\forall t
$$

#### Domain Walls
We define the interaction between two neighbouring or adjacent spins ($d_i$) in 
Eq.\eqref{interaction}. Then, we can represent the system configuration by 
these interactions. A Domain Wall (DW) refers to a hypothetical barrier in 
between different domains of spins and can be described by the interactions 
($d_i$) in the system as seen in Eq.\eqref{DWS}. The domain growth 
$(\mathcal{D}(t))$ refers to the average domain size growth. In the one 
dimensional case the growth of the average Domain size of spins can be 
represented by the decay of the fraction of Domain Walls 
$(\mathcal{D}(t) = [\mathcal{DW}(t)]^{-1})$. In this thesis we shall represent 
the DW visually with a solid line and numerically as follows:

$$
  d_i(t) \equiv \delta_{-s_i(t), s_{i+1}(t)}=
  \left\lbrace\begin{aligned}
    0 :\text{e.g. }\color{blue}\downarrow\quad\downarrow\color{none}
    &\text{ or }\color{red}\uparrow\quad\uparrow\\
    1 :\text{e.g. }\color{red}\uparrow\color{none}|
    \color{blue}\downarrow\color{none}&\text{ or }\color{blue}\downarrow
    \color{none}|\color{red}\uparrow\\
  \end{aligned}\right.\quad : i\in \nicefrac{\mathbb{Z}}{L\mathbb{Z}}
  \label{interaction}
$$

$$
  \mathcal{DW}(t) = \left\langle\left\langle d_i(t)
  \right\rangle_L\right\rangle_C
  \label{DWS}
$$

If the fraction of Domain Walls decays in a power-law 
$(\mathcal{DW}(t) \sim t^{-1/z})$ the exponent $z$ will be measured. In the 
case for Glauber Dynamics, the exponent ($z$) remains unchanged at least in 1, 
2 and 3 dimensions. The one dimensional lattice at the ground state, only has 
two DW. A visual representation of a particular configuration of spins confined 
in a finite one dimensional lattice with periodic boundary conditions in a 
possible ground state, with its corresponding spin orientation and DW is 
presented as follows:
\begin{figure}[H]
  \centering
  \begin{tabular}{ccccccccccccccccccccccccccc}
    \hline
    $|$&\color{red}$\uparrow$ & \color{red}$\uparrow$ & \color{red}$\uparrow$ & 
    \color{red}$\uparrow$ & \color{red}$\uparrow$ & \color{red}$\uparrow$ & 
    \color{red}$\uparrow$ & \color{red}$\uparrow$ & \color{red}$\uparrow$ & 
    \color{red}$\uparrow$ & \color{red}$\uparrow$ & \color{red}$\uparrow$ &$|$&
    \color{blue}$\downarrow$ & \color{blue}$\downarrow$ &
    \color{blue}$\downarrow$ & \color{blue}$\downarrow$ &
    \color{blue}$\downarrow$ & \color{blue}$\downarrow$ &
    \color{blue}$\downarrow$ & \color{blue}$\downarrow$ &
    \color{blue}$\downarrow$ & \color{blue}$\downarrow$ & \\
    \hline
  \end{tabular}
  \caption{Representation of a plausible minimal energy or ground state}
\end{figure}

#### Autocorrelation
The Autocorrelation $(\mathcal{A}(t))$ of the system represents the time 
correlation with itself at inital conditions.

$$
  \mathcal{A}(t) = \left\langle\frac{\left\langle s_i(0) s_i(t)\right\rangle_L
  -\left\langle s_i(0)\right\rangle_L\left\langle s_i(t)\right\rangle_L}
  {\sigma_0\sigma_t}\right\rangle_C
  \label{FullAC}
$$

Where $\sigma_t$, represents the standard deviation of the the lattice at time 
$t$.

$$
  \sigma_t^2 = \left\langle s_i^2(t)\right\rangle_L
  -\left\langle s_i(t)\right\rangle_L^2
$$

Since the model consists on only two states $\pm 1$, squaring the value of any 
site will only obtain $+1$. Furthermore, as previously mentioned, the global 
magnetization of spins in the lattice will maintain fixed, therefore we can 
rescribe the standard deviation as follows:

$$
  \begin{aligned}
  1 - \left\langle s_i(0)\right\rangle_L^2 
  =& 1 - \left\langle s_i(t)\right\rangle_L^2\\
  \sigma_0 =& \sigma_t
  \end{aligned}
$$

Then the Autocorrelation function can be simplified by Eq.\eqref{AC}.

$$
  \mathcal{A}(t) = \left\langle\frac{\left\langle s_i(0) s_i(t)\right\rangle_L
  -\left\langle s_i(0)\right\rangle_L^2}{1-\left\langle s_i(0)
  \right\rangle_L^2}\right\rangle_C
	\label{AC}
$$

Since the Autocorrelation is related to the domain growth exponent as 
$(\mathcal{A}(\mathcal{D}(t)) \sim [\mathcal{D}(t)]^{-\lambda})$, substituting
the Autocorrelation should decay in a power-law $\mathcal{A}(t)\sim 
t^{-\lambda/z}$. The exponent $\lambda$ is the Autocorrelation exponent which 
will be measured.

#### Persistence
The persistence probability $(\mathcal{P}(t))$ is the probability that the 
state of a spin does not change sign up to time $t$. A formal definition of the 
persistence probability for our problems is as follows. When two anti-aligned 
spins exchange their positions, the persistence of both sites are killed. We 
are interested in the decay of the persistence probability in a power-law 
$\mathcal{P}(t)\sim t^{-\theta}$, $\theta$ is the persistence probability 
exponent which will be measured. Since it is impossible to reach the 
thermodynamic limit $(L\rightarrow\infty)$, the way to process the data will 
involve the finite size scaling on the persistence probability if this reaches 
a saturation value. The general scaling law, which is true at least until now, 
can be written as follows:

$$
  \mathcal{P}(t, L) \sim t^{-\theta}f\left(\frac{L}{t^{1/z}}\right), \quad f(x)
  \sim\begin{cases}
    x^{-z\theta} : x\ll 1 \\
    \text{const} : x\gg 1 \\
  \end{cases}
$$

For the case $x\ll 1$, this is $t\rightarrow\infty$, we get 
$\mathcal{P}(t\rightarrow\infty, L)\sim L^{-z\theta}$, while for $x\gg 1$ we 
have $t^{-\theta}$. The scaling function will be used for a data collapse with 
the raw data of persistence probability in order to get the persistence 
probability exponent and the domain growth exponent within proper error bars.

## Results
We present the results for system sizes $L = 1000, 2000, 4000$ and run the 
simulations for $C = 2000$ different random initial configurations. The mean 
Magnetization Fig.[\ref{fig:RMg}] has been measured and has been conserved 
throughout the dynamics. This means that the model strictly conserves the 
Magnetization for each of the configurations. By considering at all time the 
absolute value of the Magnetization, we are able to distinguish a spin exchange 
dynamics from a spin flip dynamics. The measurable will remain conserved 
throughout the dynamics for any spin exchange dynamics while for the spin flip 
dynamics, the measurable will increase over time. The initial configurations 
are generated at random so for each initial configuration its magnetization 
will differ from zero. These small fluctuations of each initial configuration 
keep adding up by the absolute value, leading to the mean of the absolute value of Magnetization to 
differ from zero. As the Fig.[\ref{fig:RMg}] shows, for larger sizes these 
fluctuations keep diminishing tending towards zero.
\begin{figure}[H]
  \centering
  \includegraphics[width=0.65\textwidth]{../Results/No_Vacancies/GSP2S0.0000MGLN.pdf}
  \caption{mean of the absolute value of Magnetization conserved throughout all spin exchange dynamics.
  The number of different realizations was 2000.}
  \label{fig:RMg}
\end{figure}
### Spin exchange dynamics with nearest and next nearest neighbour interaction
We will reproduce and present the results for Kawasaki Dynamics and a modified 
non deterministic Schelling Model. In this thesis we shall call them as Local 
spin exchange dynamics and Global spin exchange dynamics, respectively. We will 
show results for the following observables: DW, Autocorrelation and 
Persistence.
#### Local spin exchange dynamics (Kawasaki Dynamics)
##### Domain Walls
We present the results for the decay of the fraction of Domain Walls in time 
for different temperatures Fig.[\ref{fig:RLDWS}]. It is known that if no 
temperature like noise is applied to the system then the system saturates into 
a metastable state, preventing it from reaching the ground state. When 
temperature like noise is applied to the system, the theoretical value of the 
domain growth exponent $z = 3$. We vary the temperature like noise $\beta$ 
every 0.025 starting from 0.5 until we reach the value of 0.6. 
We found that a trade off occurs as we decrease the value of $\beta$. On one 
hand the time of the system in the metastable state is extended yet, the decay 
of the fraction of DW reaches much closer to the ground state. A possible 
explanation of this behaviour is as follows. At first, the system saturates to 
a metastable state since the effects of $T$ are far less likely to produce an 
evaporation event. If $\beta$ is near or greater than the value of the critical 
temperature ($T_C$), then non critical dynamics is expected, which is out of 
scope for this study.

\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../MP3/SDWK200.pdf}
  \caption{Log-log plots for different $\beta$ of the decay of the fraction of 
           DW and its fitting in one dimension local spin exchange dynamics.
           The number of different realizations was 2000.}
  \label{fig:RLDWS}
\end{figure}

The decay of the fraction of Domain Walls is presented in a power-law with 
early time effects. We recall that if the DW present a power-law form 
$\mathcal{DW}(t)\sim t^{-1/z}$, where $z$ is the domain growth exponent. We 
ignore the first few intial MCS to avoid the early time effects if any and we 
measure only the exponent from the power-law regime. Through a least-square 
fitting, a domain growth exponent $z \approx 3.5$ can be measured. This 
difference with the analytical value is mostly due to the finite size effects.

##### Autocorrelation
We present the results of the decay of the autocorrelation function in time for
different temperatures like noise Fig.[\ref{fig:RLACK}]. The theoretical value 
of the power-law exponent is known to be $\lambda = 1$. The decay of the 
autocorrelation is presented in a power-law  with early time effects. We recall 
that if the autocorrelation presents in a power-law decay $\mathcal{A}(t)\sim 
t^{-\lambda/z}$, we measure the domain growth exponent. We ignore the first few 
intial MCS to avoid the early time effects if any and we measure only the 
power-law regime. For the autocorrelation we are able to identify longer early 
time effects as the temperature like noise is decreased. Through a least-square 
fitting in the range of $[10^4, 10^6]$ the autocorrelation decays in power-law 
with an exponent $1/3$. To compute $\lambda$ it is convinient to study the 
relationship between the autocorrelation as a function of the average Domain 
growth ($\mathcal{A}(t)\sim f(D(t))$). We plot this relationship and obtain the 
following graph.

\begin{figure}[H]
  \centering
  \includegraphics[width=0.90\textwidth]{../MP3/SACK200.pdf}
  \caption{Log-log plots for different $\beta$ of the decay of the 
           autocorrelation function and its fitting in one dimension local spin 
           exchange dynamics. The number of different realizations was 2000. The 
           inset plot displays the decay of the Autocorrelation as a function of  
           the Domain size $\langle D\rangle$}
  \label{fig:RLACK}
\end{figure}
##### Persistence
We present the results of the decay of the persistence probability in time for
different temperatures like noise Fig.[\ref{fig:RLPtK}]. The theoretical value 
of the power-law exponent has not been reported and the reason for this is 
that, as shown in Fig.[\ref{fig:RLPtK}], it does not present a power-law decay.
\begin{figure}[H]
  \centering
  \includegraphics[width=0.95\textwidth]{../MP3/SPtK200.pdf}
  \caption{Log-normal plots for different $\beta$ of the decay of the 
           persistence probability in one dimension local spin exchange 
           dynamics. The number of different realizations was 2000.}
  \label{fig:RLPtK}
\end{figure}

#### Global spin exchange dynamics (Schelling Model)
##### Domain Walls
We present the results for the decay of the fraction of Domain Walls in time 
for system sizes $500, 1000, 2000$. Fig.[\ref{fig:RGDWK}]. We vary the window 
and present the results for $w = 1, 3$. The decay of the fraction of Domain 
Walls is presented in a power-law with early time effects. We recall that if 
the DW presents in a power-law decay $\mathcal{DW}(t)\sim t^{-1/z}$, we 
measure the domain growth exponent. We ignore the first few intial MCS to avoid 
the early time effects if any and we measure only the power-law regime. 
Through a least-square fitting in the range of $[500, 10^6]$, a domain growth 
exponent $z \approx 3$ can be measured, Fig.[\ref{fig:RGDWK}]. This change of 
the value could be due to small Lattice sizes.

The global spin exchange dynamics has a critical temperature at zero 
($T_C = 0$), hence we will only present the results for zero temperature like 
noise. For any non zero temperature like noise applied to the system, the 
system does not remain critical (*i.e.* the measured Domain Walls 
observable and the following measured observables do not present a power law 
decay).

\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/G2S0.0000DWLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
  fraction of Domain Walls and its fitting. The number of different 
  realizations was 2000.}
  \label{fig:RGDWK}
\end{figure}
\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/G2S3DWLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           fraction of Domain Walls and its fitting. The number of different 
           realizations was 2000.}
\end{figure}
##### Autocorrelation
We present the results for the decay of the autocorrelation and persistence 
function in time for different system sizes Fig. [\ref{fig:RGACK_1},
\ref{fig:RGACK_2}, \ref{fig:RGPtK_1}, \ref{fig:RGPtK_2}]. To compute $\lambda$ 
it is convinient to study the relationship between the autocorrelation as a 
function of the average Domain growth ($\mathcal{A}(t)\sim f(\mathcal{D}(t))$). 
We plot this relationship and obtain the following graphs for $w = 1, 3$

The autocorrelation decays in a power-law $\mathcal{A}(t)\sim t^{-\lambda/z}$ 
with early time effects. We ignore the first few intial MCS to avoid the early 
time effects if any and we measure only the power-law regime. Through a 
least-square fitting in the range of $[500, 10^6]$, $\lambda = 1$ for both 
cases of $w = 1, 3$. For the autocorrelation we are able to identify longer 
early time effects when the window size is extended.

\begin{figure}[H]
  \centering
  \includegraphics[width=0.95\textwidth]{../Results/No_Vacancies/G2S0.0000ACLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           autocorrelation function and its fitting. The number of different 
           realizations was 2000. The inset plot displays the decay of the 
           Autocorrelation as a function of the average Domain size $\langle 
           \mathcal{D}\rangle$}
  \label{fig:RGACK_1}
\end{figure}

\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/G2S3ACLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           autocorrelation function and its fitting. The number of different 
           realizations was 2000. The inset plot displays the decay of the 
           Autocorrelation as a function of the average Domain size $\langle 
           \mathcal{D}\rangle$}
  \label{fig:RGACK_2}
\end{figure}
##### Persistence
The persistence decays in a power-law $\mathcal{P}(t)\sim t^{-\theta}$ with 
early time effects. We ignore the first few intial MCS toavoid the early time 
effects if any and we measure only the power-law regime. Through a least-square 
fitting in the range of $[500, 10^6]$, $\theta \sim 3/10, 1/4$ for both cases 
of $w = 1, 3$, respectively. Similarly, the persistence presents longer early 
time effects when the window size is extended.
\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/G2S0.0000PtLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           persistence probability and its fitting. The number of different 
           realizations was 2000.}
  \label{fig:RGPtK_1}
\end{figure}
\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/G2S3PtLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           persistence probability and its fitting. The number of different 
           realizations was 2000.}
  \label{fig:RGPtK_2}
\end{figure}
\begin{comment}
We can summarize these results in a table as follows:
\begin{table}[H]
  \begin{center}
    \begin{tabular}{| c | c | c | c | c | c |}
      \hline
      Dynamics & $T$ & $w$ & $z$ & $\lambda$ & $\theta$ \\
      \hline
      Kawasaki & 0.55 & 1 & 3 & 1 & - \\
      \hline
      Schelling & 0 & 1 & 3 & 1 & 3/10 \\
      \hline
      Schelling & 0 & 3.5 & 3 & 1 & 1/4 \\
      \hline
      Social Pressure & 0 & 2.5 & 1.2 & 1 & 1/2 \\
      \hline
      Schelling & 0 & 3 & 3 & 1 & 1/4 \\
      \hline
      Schelling & 0 & 3 & 3 & 1 & 1/4 \\
      \hline
      Schelling & 0 & 3 & 3 & 1 & 1/4 \\
      \hline
      Schelling & 0 & 3 & 3 & 1 & 1/4 \\
      \hline
      Schelling & 0 & 3 & 3 & 1 & 1/4 \\
      \hline
    \end{tabular}
  \end{center}
  \caption{A}
\end{table}
\end{comment}


### Global spin exchange dynamics under Social Pressure
#### Zero temperature
##### Domain Walls
The decay of the fraction of Domain Walls in time for different system sizes 
Fig.[\ref{fig:RDWSP}]. This decay is presented in a power-law with early time 
effects and an exponential decay at the end before reaching the saturation 
value equal to $2/L$. We recall that if the DW presents a power-law  
$\mathcal{DW}(t)\sim t^{-1/z}$, we measure the domain growth exponent. We 
ignore the first few intial MCS to avoid the early time effects if any and we 
measure only the power-law regime. Through a least-square fitting in the 
range of $[3, L/20]$, a domain growth exponent $z \approx 2.48$ can be 
measured, Fig.[\ref{fig:RDWSP}].
\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/GSP2S0.0000DWLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           fraction of Domain Walls in time and its fitting. The number of 
           different realizations was 2000.}
  \label{fig:RDWSP}
\end{figure}
##### Autocorrelation
The autocorrelation function in time for different system sizes 
Fig.[\ref{fig:RACSP}]. We can appreciate a power-law decay $\mathcal{A}(t)\sim 
t^{-\lambda/z}$ with a large early time effects. Although it appears to 
saturate at a certain value, the autocorrelation function will start to 
fluctuate around a certain range. These fluctuations depend on the spatial 
correlations of the initial configuration. In order to measure the value of the 
exponent, we ignore the first few intial MCS to avoid the early time effects 
and we measure only the power-law regime. To compute $\lambda$ it is convinient 
to study the relationship between the autocorrelation as a function of the 
average Domain growth ($\mathcal{A}(t)\sim f(\mathcal{D}(t))$). Through a 
least-square fitting in the range of $[5, L/10]$, an autocorrelation exponent 
$\lambda\approx 1.15$, can be measured Fig.[\ref{fig:RACSP}].
\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/GSP2S0.0000ACLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           Autocorrelation function in time and its fitting. The number of
           different realizations was 2000. The inset plot displays the 
           decay of the Autocorrelation as a function of the average Domain 
           size $\langle \mathcal{D}\rangle$}
  \label{fig:RACSP}
\end{figure}

##### Persistence
The decay of the persistence probability for different system sizes 
Fig.[\ref{fig:RPtSP}]. We can appreciate a power-law decay $\mathcal{P}(t)\sim 
t^{-\theta}$ with a large early time effects. We ignore the first few intial 
MCS to avoid the early time effects if any and we measure only the power-law 
regime. Through a least-square fitting in the range of $[3, L/2]$, we can 
obtain a persistence exponent $\theta\sim 0.42$. After the power-law decay the 
persistence probability appears to be saturating. However, we can expect the 
persistence probability of the system, actually decreases and eventually will 
have an exponential decay reaching zero. The explanation is as follows. 
\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/GSP2S0.0000PtLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           persistence probability and its fitting. The number of different 
           realizations was 2000.}
  \label{fig:RPtSP}
\end{figure}


Even if the system has reached one of the possible ground states, that does not 
mean it necesarrily has to stop evolving in time. It is possible that when the 
non-neighbouring spins of each domain boundaries are selected, 
*shifting* the entire domain either to the left or right hand side by 
one lattice site of its current position. This type of movement are held by 
diffusion events. If so, the domains of spins are expected in average to cycle 
around the lattice, hence none of the sites will persist at long time. An 
example of this situation is presented in Fig.[\ref{fig:RLtSP}], where once the 
system has reached to ground state, where both domains are consolidated, at 
time 80 the right boundary spin of the red domain and the left boundary spin 
from the blue domain are selected and exchanged their position, *moving* 
the red domain to the left.

\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../MP3/TLSPG.pdf}
  \caption{Snapshot of the evolution in time of the Lattice ($L = 50$) until 
           the system reaches the ground state and a few more MCS to show the
           shift of the domains.}
  \label{fig:RLtSP}
\end{figure}

##### Data collapse
We recall that the $\mathcal{P}(t)\sim t^{-\theta}$, then from the power-law 
regime we can measure the exponent $\theta \approx 0.46$. After this we have a 
slowly decaying, almost saturating, part and then an exponential decay. The 
criteria for a scaling law [link](scaling) $(z\theta\leq D = 1)$ is being 
violated, hence if we do a collapse we will not expect a domain growth exponent 
$(z_S)$ to be the same as the one measured previously $(z)$.
Despite the absence of a saturation value, we do a data collapse of the results 
before the exponentially decaying part Fig. [\ref{fig:RDC}].
\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/GSP2S0.0000DCLL.pdf}
  \caption{Finite size scaling for persistence probability $z = 1 \pm 0.01$ and 
           $\theta = 0.44\pm 0.005$. Inset shows the unscaled data of the 
           average persistence probability decay in time and its fitting in 
           logarithmic scale. The number of different realizations was 2000.}
  \label{fig:RDC}
\end{figure}

With simple fit done with the use of the eye, we can appreciate that it does 
collapse properly before the exponential decay. In addition to this, the values 
used for the inexact fit where $(z_S = 1 \pm 0.01, \theta_S = 0.44 \pm 0.005)$. 
We can see that the dynamical exponent $(z_S \neq z)$ differs drastically from 
the previous results obtained in Fig. [\ref{fig:RDWSP}]. This suggest that 
there could exist a secondary domain growth exponent. It is needed a detailed 
study to understand if there is a second domain growth exponent and the reasons 
to the difference in the dynamical exponent, which could be addressed in a 
completely different project.

#### Positive temperature
As expected, for any non-zero temperature like noise applied, the fraction of 
Domain Walls mainly remains flat with very little fluctuation, which says that 
the system maintained in a disordered state throughout time. None of the 
obtained results presented a phase transition. The Autocorrelation function and 
persistence probability do present a decay in time. Autocorrelation decays with 
time, but not in a power law fashion, therefore the Autocorrelation is not 
displayed as it does not provide any informative value. The Persistence 
probability has been plotted in a log normal graph. As it is a straight line in 
log normal that means it decays exponentially.

\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/GSP2ST0.1500DWLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           fraction of Domain Walls in time. The number of different 
           realizations was 2000.}
  \label{fig:}
\end{figure}

\begin{figure}[H]
  \centering
  \includegraphics[width=\textwidth]{../Results/No_Vacancies/GSP2ST0.1500PtLL.pdf}
  \caption{Log-log plots for different lattice sizes of the decay of the 
           fraction of Domain Walls in time. The number of different 
           realizations was 2000.}
  \label{fig:}
\end{figure}

## Conclusions and discussions
The conserved spin exchange dynamics in an Ising spin system under Social 
Pressure in one dimension have been simulated and analyzed. A thorough analysis 
of the novel domain size dependent dynamics on the basis of racial segregation 
has been inspired through the framework of two well known models, Kawasaki 
dynamics and Schelling Model. As expected, for Global spin exchange dynamics 
(*i.e.* Schelling Model) and domain size dependent Global spin exchange 
dynamics, at the presence of temperature like noise, the system does not remain 
critical (*i.e.* the measured observables do not present a power law 
decay). The Persistence probability in the domain size dependent Global spin 
exchange dynamics with temperature like noise has been plotted in a log normal 
graph. As it is a straight line in log normal that means it decays 
exponentially. In contrast, for the Local spin exchange dynamics, temperature 
like noise is a necessary external influence to remain the dynamics critical, 
but the power law behaviour (for some of the observables) is seen more clearly 
as temperature takes out the system from the freezing. 

We obtained the analytical values of the power-law decay exponents for the well 
known models, Kawasaki dynamics and Schelling model. We present the numerical 
difficulties of reaching the ground state of the Kawasaki dynamics as the 
temperature like noise plays an important role in maintaining the dynamics 
critical. We also present the results of the global spin exchange dynamics by 
extending the range of interaction on the fixed window size ($w$) from nearest 
to next to nearest, resulting in a behaviour of the dynamics of extended early 
time effect, yet the power-law behaviour can still be well appreciated. 

We present the results of the decay of the fraction of Domain Walls in time in 
a logarithmic scale in Fig.[\ref{fig:RDWSP}]. The domain growth exponent value 
obtained by the results that $z \approx 2.48$. We can observe some early time 
effects, as well as an exponential decay at the tail before reaching the ground 
state. It is clear to see that in an exchanging dynamics the ground state 
refers to the state with only two Domain Walls, resulting this in a saturation 
value. Even if the system had reached the ground state, the system could still 
be evolving to an equally probable state. In other words, the boundaries of the 
anti-aligned domains of spins should be exchanging places. A visual 
representation of this effect can be seen in Fig.[\ref{fig:RLtSP}], where the 
domain boundary spin can exchange places with a non-neighbouring anti-aligned 
domain boundary spin, producing the effect of sliding the entire domain of 
spins to the left or to the right by one lattice site.

Similarly the measured Autocorrelation function (Fig.[\ref{fig:RACSP}]) and 
Persistence probability (Fig.[\ref{fig:RPtSP}]) is presented in a power-law 
decay with an early time effect. From the results we are able to extract the 
power-law exponent values of the Autocorrelation function and persistence 
probability, $(\lambda \approx 1.15, \theta \approx 0.46)$, respectively. Due 
to the *movement* of the domain in time after reaching the ground state, 
the Autocorrelation function fluctuates around a certain range, meanwhile all 
spins lose their persistence.

After a very slowly decaying persistence probability, we expect it to decay to 
zero. With the use of finite size scaling we are able to do a data collapse. We 
can appreciate that it does collapse properly before the exponential decay. The 
values used for the data collapse $(z_S = 1 \pm 0.01, \theta_S = 0.44 \pm 
0.005)$ differ from the obtained results specially for the correlation length. 
The reasons to the difference in the dynamical exponent, will be addressed in a 
completely different project. These new results add more value to the long 
standing theory of the data collapse. This results provide a counter example to 
the mathematical artifact used to establish a single exponent. As we have 
shown, this exponent may not be unique, providing us with further insights yet 
to be discovered.
## Objectives
1. Apply High Performance Computing (HPC) techniques to solve Spin systems

## Methodology

## Results