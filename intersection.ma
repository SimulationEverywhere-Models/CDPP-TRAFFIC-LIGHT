[top]

components : Gens
components : Qs
components : Lights
components : button@Button
components : sensor@Sensor
Link : car_E@Gens car_E@Qs
Link : car_N@Gens car_N@Qs
Link : ped_NS@Gens ped_NS@Qs
Link : ped_EW@Gens ped_EW@Qs
Link : EW_car_Q@Qs car_in_Q@sensor
Link : EW_ped_Q@Qs ped_in_Q@button
Link : button_on@button button_on@Lights
Link : sensor_set@sensor sensor_set@Lights
Link : walk_stop_EW@Lights walk_stop@button
Link : light_red_EW@Lights light_red@sensor
Link : light_red_EW@Lights fill_Q_car_EW@Qs
Link : light_red_NS@Lights fill_Q_car_NS@Qs
Link : walk_stop_EW@Lights fill_Q_ped_EW@Qs
Link : walk_stop_NS@Lights fill_Q_ped_NS@Qs
Link : light_green_EW@Lights empty_Q_car_EW@Qs
Link : light_green_NS@Lights empty_Q_car_NS@Qs
Link : walk_EW@Lights empty_Q_ped_EW@Qs
Link : walk_NS@Lights empty_Q_ped_NS@Qs


[Qs]

components : car_E_Q@Queue
components : car_N_Q@Queue
components : ped_EW_Q@Queue
components : ped_NS_Q@Queue
in : car_N
in : car_E
in : ped_NS
in : ped_EW
in : fill_Q_car_EW
in : fill_Q_car_NS
in : fill_Q_ped_EW
in : fill_Q_ped_NS
in : empty_Q_car_EW
in : empty_Q_car_NS
in : empty_Q_ped_EW
in : empty_Q_ped_NS
out : EW_car_Q
out : EW_ped_Q
Link : car_N enqueue@car_N_Q
Link : car_E enqueue@car_E_Q
Link : ped_EW enqueue@ped_EW_Q
Link : ped_NS enqueue@ped_NS_Q
Link : add@ped_EW_Q EW_ped_Q
Link : add@car_E_Q EW_car_Q
Link : fill_Q_car_EW fill_Q@car_E_Q
Link : fill_Q_car_NS fill_Q@car_N_Q
Link : fill_Q_ped_EW fill_Q@ped_EW_Q
Link : fill_Q_ped_NS fill_Q@ped_NS_Q
Link : empty_Q_car_EW empty_Q@car_E_Q
Link : empty_Q_car_NS empty_Q@car_N_Q
Link : empty_Q_ped_EW empty_Q@ped_EW_Q
Link : empty_Q_ped_NS empty_Q@ped_NS_Q


[Gens]

components : car_gen_N@Generator
components : car_gen_E@Generator
components : ped_gen_NS@Generator
components : ped_get_EW@Generator
out : car_N
out : car_E
out : ped_EW
out : ped_NS
Link : out@car_gen_N car_N
Link : out@car_gen_E car_E
Link : out@ped_gen_NS ped_NS
Link : out@ped_gen_EW ped_EW


[Lights]

components : Traffic
components : Walk
in : sensor_set
in : button_on
out : light_green_NS
out : light_red_NS
out : light_green_EW
out : light_red_EW
out : walk_EW
out : walk_NS
out : walk_stop_EW
out : walk_stop_NS
Link : sensor_set sensor_set@Traffic
Link : button_on button_on@Walk
Link : light_green_NS@Traffic light_green_NS
Link : light_green_EW@Traffic light_green_EW
Link : light_red_NS@Traffic light_red_NS
Link : light_red_EW@Traffic light_red_EW
Link : walk_NS@Walk walk_NS
Link : walk_EW@Walk walk_EW
Link : walk_stop_NS@Walk walk_stop_NS
Link : walk_stop_EW@Walk walk_stop_EW
Link : walk_stop_NS@Walk walk_stop_NS@Traffic
Link : walk_stop_EW@Walk walk_stop_EW@Traffic
Link : light_green_NS@Traffic light_green_NS@Walk
Link : light_green_EW@Traffic light_green_EW@Walk


[Traffic]

components : light_NS@Light
components : light_EW@Light
in : walk_stop_NS
in : walk_stop_EW
out : light_green_NS
out : light_green_EW
out : light_red_NS
out : light_red_EW
Link : walk_stop_NS walk_stop@light_NS
Link : walk_stop_EW walk_stop@light_EW
Link : light_green@light_NS light_green_NS
Link : light_green@light_EW light_green_EW
Link : light_red@light_NS light_red_NS
Link : light_red@light_EW light_red_EW
Link : light_red@light_NS opp_light_red@light_EW
Link : light_red@light_EW opp_light_red@light_NS


[Walk]

components : EW@Walk_No_But_Sen
components : NS@Walk_But_Sen
in : sensor_set
in : button_on
in : light_green_NS
in : light_green_EW
out : walk_EW
out : walk_stop_EW
out : walk_NS
out : walk_stop_NS
Link : button_on button_on@NS
Link : sensor_set sensor_set@NS
Link : light_green_NS light_green@NS
Link : light_green_EW light_green@EW
Link : walk@EW walk_EW
Link : walk_stop@EW walk_stop_EW
Link : walk@NS walk_NS
Link : walk_stop@NS walk_stop_NS


[car_gen_N]
distribution : normal
mean : 6
deviation : 3

[car_gen_E]
distribution : normal
mean : 180
deviation : 30

[ped_gen_NS]
distribution : normal
mean : 120
deviation : 20

[ped_gen_EW]
distribution : normal
mean : 300
deviation : 60
