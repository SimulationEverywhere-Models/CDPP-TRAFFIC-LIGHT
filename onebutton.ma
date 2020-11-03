[top]

component : button@Button
in : ped_in_Q walk_stop
out : button_on
Link : ped_in_Q ped_in_Q@button
Link : walk_stop walk_stop@button
Link : button_on@button button_on