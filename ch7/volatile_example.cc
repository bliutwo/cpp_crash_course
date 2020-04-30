int foo(int& x) {
    x = 10;
    x = 20;  // x never used before reassignment: a straightforward candidate
             // for getting optimized away - a dead store
    auto y = x;
    y = x;   // x is used to set the value of y twice without any intervening
             // instructions - a redundant load, also a candidate for optimization
    return y;
}

// a compiler's optimization of the above version of foo()
int foo(int& x) {
    x = 20;
    return x;
}

// But "[I]n some settings, the redundant reads and dead stores might have
// visible side effects on the system. By adding the volatile keyword to the
// argument of foo, you can avoid the optimizer getting rid of these important
// accesses.
int foo(volatile int& x) {
    x = 10;
    x = 20;  // x never used before reassignment: a straightforward candidate
             // for getting optimized away - a dead store
    auto y = x;
    y = x;   // x is used to set the value of y twice without any intervening
             // instructions - a redundant load, also a candidate for optimization
    return y;
}

// Note that volatile has nothing to do with concurrent programming (a common
// misconception). Variables marked volatile are not generally thread safe.
// Do'nt confuse volatile with atomic!
