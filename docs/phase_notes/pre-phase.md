# 📘 Session Summary — Foundations of Differential Drive & Nonholonomic Systems

## 1️⃣ Differential Drive Model

A differential drive robot:

* Has two independently actuated wheels on a common axle.
* Motion is controlled through wheel velocity differences.
* Can move forward/backward and rotate, but cannot move laterally.

Core velocity relationships:
$$
v = \frac{v_r + v_l}{2}

\\

\omega = \frac{v_r - v_l}{L}

$$
Where:

* $v$ = forward velocity
* $ \omega $ = angular velocity
* $ L $ = wheel separation

The planar kinematic model (unicycle model):

$$
\dot{x} = v \cos\theta

\\

\dot{y} = v \sin\theta

\\

\dot{\theta} = \omega
$$

---

## 2️⃣ Nonholonomic Constraint

A differential drive robot is **nonholonomic** because it has velocity constraints that cannot be integrated into position-only constraints.

The constraint:

$$
\dot{x}\sin\theta - \dot{y}\cos\theta = 0
$$

This enforces that velocity is aligned with the robot’s forward axis.

Key insight:

* Instantaneously, the robot cannot move sideways.
* Over time, by changing heading, it can reach any planar position.
* The constraint always exists — but reachable space grows via sequential admissible motions.

This is fundamental for:

* Motion planning
* Control design
* State estimation
* Understanding why parking-like maneuvers work

---

## 3️⃣ State Representation

Minimum 2D pose state:

$$
\mathbf{x} = [x, y, \theta]
$$

Important distinction:

* Pose = configuration state
* Velocities = derivatives of configuration

This matters critically for:

* Odometry
* Kalman filtering
* SLAM

---

## 4️⃣ Robotics Competency Roadmap Context

Related to:

Layer 3 — Kinematics & Control 

But this connects upward into:

* State Estimation (EKF depends on this model)
* Navigation (planner must respect nonholonomic constraints)
* Multi-robot systems (each robot follows same kinematics)

You also reviewed the structured multi-phase roadmap and long-term architecture direction .

---

## 5️⃣ Engineering Perspective

Why this matters:

* Every estimator we build will assume this motion model.
* Every controller will command ($v, \omega$).
* Every planner must respect nonholonomic feasibility.
* Every simulator plugin is implementing these equations under the hood.

If this model is not internalized, everything later becomes fragile.
