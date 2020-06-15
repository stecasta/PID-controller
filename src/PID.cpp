#include "PID.h"
#include <ctime>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

double Kp;
double Ki;
double Kd;
double last_cte;
double cte_d;
double cte_i;
double last_update;


void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  cte_d = 0;
  cte_i = 0;
  last_cte = 0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  double dt = last_update - std::time(0);
  last_update = std::time(0);
  cte_d = cte - last_cte;
  cte_i += cte;
  last_cte = cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return 0.0;  // TODO: Add your total error calc here!
}