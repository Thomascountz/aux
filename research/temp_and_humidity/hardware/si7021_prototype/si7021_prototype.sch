EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Si7021 Prototype"
Date "2021-02-21"
Rev "1"
Comp "Countz Research"
Comment1 "New York City"
Comment2 "Thomas Countz"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP32_mini:mini_esp32 U2
U 1 1 6032D049
P 5850 2800
F 0 "U2" H 5875 2925 50  0000 C CNN
F 1 "mini_esp32" H 5875 2834 50  0000 C CNN
F 2 "ESP32_mini:ESP32_mini" H 6000 2900 50  0001 C CNN
F 3 "" H 6000 2900 50  0001 C CNN
	1    5850 2800
	1    0    0    -1  
$EndComp
NoConn ~ 6400 4500
NoConn ~ 6400 4400
NoConn ~ 6400 4300
NoConn ~ 6400 4200
NoConn ~ 6400 4100
NoConn ~ 6400 4000
NoConn ~ 6400 3900
NoConn ~ 6400 3400
NoConn ~ 5350 2900
NoConn ~ 5350 3000
NoConn ~ 5350 3100
NoConn ~ 5350 3200
NoConn ~ 5350 3300
NoConn ~ 5350 3400
NoConn ~ 5350 3500
NoConn ~ 5350 3600
NoConn ~ 5350 3700
NoConn ~ 5350 3800
NoConn ~ 5350 3900
NoConn ~ 5350 4000
NoConn ~ 5350 4100
NoConn ~ 5350 4200
NoConn ~ 5350 4300
NoConn ~ 5350 4400
NoConn ~ 5350 4500
NoConn ~ 5350 4600
NoConn ~ 5350 4700
NoConn ~ 5350 5000
NoConn ~ 5350 5100
NoConn ~ 5350 5200
NoConn ~ 5350 5300
$Comp
L power:+3.3V #PWR0101
U 1 1 60338092
P 4800 5150
F 0 "#PWR0101" H 4800 5000 50  0001 C CNN
F 1 "+3.3V" H 4815 5323 50  0000 C CNN
F 2 "" H 4800 5150 50  0001 C CNN
F 3 "" H 4800 5150 50  0001 C CNN
	1    4800 5150
	1    0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR0102
U 1 1 60338D3F
P 6750 3000
F 0 "#PWR0102" H 6750 2850 50  0001 C CNN
F 1 "+3.3V" H 6765 3173 50  0000 C CNN
F 2 "" H 6750 3000 50  0001 C CNN
F 3 "" H 6750 3000 50  0001 C CNN
	1    6750 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3000 6750 3000
$Comp
L power:+5V #PWR0103
U 1 1 60339AD7
P 6550 2900
F 0 "#PWR0103" H 6550 2750 50  0001 C CNN
F 1 "+5V" H 6565 3073 50  0000 C CNN
F 2 "" H 6550 2900 50  0001 C CNN
F 3 "" H 6550 2900 50  0001 C CNN
	1    6550 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 2900 6550 2900
$Comp
L power:GND #PWR0104
U 1 1 6033ADD4
P 6750 3300
F 0 "#PWR0104" H 6750 3050 50  0001 C CNN
F 1 "GND" H 6755 3127 50  0000 C CNN
F 2 "" H 6750 3300 50  0001 C CNN
F 3 "" H 6750 3300 50  0001 C CNN
	1    6750 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 6033BCA8
P 4800 4650
F 0 "#PWR0105" H 4800 4400 50  0001 C CNN
F 1 "GND" H 4805 4477 50  0000 C CNN
F 2 "" H 4800 4650 50  0001 C CNN
F 3 "" H 4800 4650 50  0001 C CNN
	1    4800 4650
	1    0    0    1   
$EndComp
$Comp
L usini_sensors:module_si7021 U1
U 1 1 60343173
P 4650 4550
F 0 "U1" H 4817 5225 50  0000 C CNN
F 1 "module_si7021" H 4817 5134 50  0000 C CNN
F 2 "usini_sensors:module_si7021" H 4900 4550 50  0001 C CNN
F 3 "" H 4650 4550 50  0001 C CNN
	1    4650 4550
	-1   0    0    1   
$EndComp
Wire Wire Line
	4650 4700 4800 4700
Wire Wire Line
	4800 4700 4800 4650
Wire Wire Line
	4650 5000 4800 5000
Wire Wire Line
	4800 5000 4800 5150
Wire Wire Line
	4650 4800 5350 4800
Wire Wire Line
	4650 4900 5350 4900
Wire Wire Line
	6400 3300 6750 3300
Wire Wire Line
	6400 3200 6750 3200
Connection ~ 6750 3300
Wire Wire Line
	6400 3100 6750 3100
Wire Wire Line
	6750 3100 6750 3200
Connection ~ 6750 3200
Wire Wire Line
	6750 3200 6750 3300
$EndSCHEMATC
