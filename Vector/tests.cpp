#include <chrono>
#include <iostream>
#include "Vector.h"
#include <random>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());