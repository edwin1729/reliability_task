# Repo containing completed tasks for UROP application to Software Reliability Group

## Task 1
*malloc\_intercept.c* contains the wrapper function to malloc. 
*make* generates *malloc_intercept.so* which can be used in
```LD_PRELOAD=/full/path/to/malloc_intercept.so seq 1 5```
