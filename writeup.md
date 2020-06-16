# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Introduction

PID controllers are by far the most used type of controllers. The reason behind this is that they are simple and
 effective.
 
 In this project the goal was to implement a generic PID controller and then tune it, in order to control the heading
  of the car in the simulation environment.
  
  In the following I will first describe the effect of each term on the behavior of the system and then I'll explain
   the tuning procedure that I followed.
  
## PID Gains

Each term of the controller contributes to make it either faster, more stable or more precise. Changing the values of
 the gains will impact positively some qualities but it will likely have its drawbacks too. It is crucial to
  understand the contribution of each term in order to fine the controller and achieve the best results for the system.

### Proportional Term
The P term is directly proportional to the error, so the higher the error, the higher the P term contribution
. Increasing this
 term will make us
 converge to the
 desired
 value faster, but it will also cause oscillations and potentially make the system unstable.
 
 When I used a small value for the P gain (0.01), the car divres smoothly, but it doesn't turn fast enough in turns.
 When I plugged a high value (0.5) the car starts overshooting and oscillating already in the first straight and goes
  off track.
 
 ### Derivative Term
 The D term is proportional to the change rate of the error, so the more the error is changing, the more this term
  will count.
Increasing the D gain, will ideally make the convergence smoother, but if we exaggerate we could enhance the
 overshooting
 behavior
. The derivative
 term also
 helps to
 mitigate the
 effect of drift.
 
 When I used a P value of 0.05 and used a very large D term (5), the system starts overshooting from the beginning
  and goes off-road.
 . On the
  other
  hand, starting from small D values, going up until 1.5, the oscillating behavior is more and more mitigated as
   expected.

### Integral Term
The I term is proportional to the integral of the error, this means that it takes into account the error history
, thus it makes the error go to zero even in the presence of model bias. The downside of increasing the I term is
 that it make the system less reactive.
 
 In the implementation, when I used a large value of I (P=0.05, I=0.1, D=1.5), the system overshoots since it is
  weighting previous errors way too much. 
   

## PID Tuning

I decided to tune the controller with a trial and error technique in order to understand better the effect of each
 term on the behavior of the controller. I followed the Ziegler-Nichols method.
 
 First, I increased the P term until the car started to oscillate. This value was P = 0.05. Then I increased the D value
  until the oscillation went away (D = 1.5).
  Step 1 and 2 were iterated until the derivative effect couldn't stabilize anymore the system. This values were P = 0.06 and D = 1.29.
 For this project the I term didn't seem to have a great impact, probably because we are using a simulation and the
  model error is not an issue. The place where it did seem to help was in sharp turns. I found that a good value for
   the I term was 0.0001. 
   The final configuration is (0.05, 0.0001, 1.5)
