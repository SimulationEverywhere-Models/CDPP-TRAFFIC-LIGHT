[top]

components : queue@Queue
in : enqueue empty_Q fill_Q
out : remove add
Link : enqueue enqueue@queue
Link : empty_Q empty_Q@queue
Link : fill_Q fill_Q@queue
Link : remove@queue remove
Link : add@queue add