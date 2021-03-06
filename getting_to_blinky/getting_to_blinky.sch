EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Getting to Blinky 5.0"
Date "2021-03-11"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 "Countz Research"
Comment4 "Thomas Countz"
$EndDescr
$Comp
L gtb:7555 U1
U 1 1 604B7F99
P 6050 3750
F 0 "U1" H 6000 3700 50  0000 L CNN
F 1 "7555" H 5950 3800 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6200 3200 50  0001 C CNN
F 3 "" H 6200 3200 50  0001 C CNN
F 4 "X" H 6050 3750 50  0001 C CNN "Spice_Primitive"
F 5 "NE555" H 6050 3750 50  0001 C CNN "Spice_Model"
F 6 "Y" H 6050 3750 50  0001 C CNN "Spice_Netlist_Enabled"
F 7 "/Users/thomascountz/Documents/Projects/Personal/KiCad-Spice-Library/Models/uncategorized/Bordodynovs Electronics Lib/sub/NE555.sub" H 6050 3750 50  0001 C CNN "Spice_Lib_File"
	1    6050 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 604BA330
P 6750 3900
F 0 "R3" H 6820 3946 50  0000 L CNN
F 1 "1K" H 6820 3855 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 6680 3900 50  0001 C CNN
F 3 "~" H 6750 3900 50  0001 C CNN
	1    6750 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 604BAD91
P 5150 4500
F 0 "C1" H 5265 4546 50  0000 L CNN
F 1 "1U" H 5265 4455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 5188 4350 50  0001 C CNN
F 3 "~" H 5150 4500 50  0001 C CNN
	1    5150 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 604BB90F
P 6750 4450
F 0 "D1" V 6789 4332 50  0000 R CNN
F 1 "LED" V 6698 4332 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6750 4450 50  0001 C CNN
F 3 "~" H 6750 4450 50  0001 C CNN
F 4 "D" H 6750 4450 50  0001 C CNN "Spice_Primitive"
F 5 "LED_GENERAL" H 6750 4450 50  0001 C CNN "Spice_Model"
F 6 "Y" H 6750 4450 50  0001 C CNN "Spice_Netlist_Enabled"
F 7 "/Users/thomascountz/Documents/Projects/Personal/KiCad-Spice-Library/Models/Diode/led.lib" H 6750 4450 50  0001 C CNN "Spice_Lib_File"
	1    6750 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 604BC464
P 4550 3950
F 0 "BT1" H 4668 4046 50  0000 L CNN
F 1 "CR2032" H 4668 3955 50  0000 L CNN
F 2 "getting_to_blinky:S8211-46R" V 4550 4010 50  0001 C CNN
F 3 "~" V 4550 4010 50  0001 C CNN
F 4 "V" H 4550 3950 50  0001 C CNN "Spice_Primitive"
F 5 "dc 5" H 4550 3950 50  0001 C CNN "Spice_Model"
F 6 "Y" H 4550 3950 50  0001 C CNN "Spice_Netlist_Enabled"
	1    4550 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 604BD33B
P 5950 5100
F 0 "#PWR0101" H 5950 4850 50  0001 C CNN
F 1 "GND" H 5955 4927 50  0000 C CNN
F 2 "" H 5950 5100 50  0001 C CNN
F 3 "" H 5950 5100 50  0001 C CNN
	1    5950 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 604B9E81
P 5150 3900
F 0 "R2" H 5220 3946 50  0000 L CNN
F 1 "470K" H 5220 3855 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 5080 3900 50  0001 C CNN
F 3 "~" H 5150 3900 50  0001 C CNN
	1    5150 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 604B9938
P 5150 3350
F 0 "R1" H 5220 3396 50  0000 L CNN
F 1 "1K" H 5220 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 5080 3350 50  0001 C CNN
F 3 "~" H 5150 3350 50  0001 C CNN
	1    5150 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3750 4550 3100
Wire Wire Line
	4550 3100 5150 3100
Wire Wire Line
	5950 3100 5950 3250
Wire Wire Line
	5950 3100 6150 3100
Wire Wire Line
	6150 3100 6150 3250
Wire Wire Line
	5150 3100 5150 3200
Wire Wire Line
	5150 4050 5150 4350
Wire Wire Line
	5150 3500 5150 3650
Connection ~ 5150 3100
Wire Wire Line
	5550 4050 5450 4050
Wire Wire Line
	5550 3850 5450 3850
Wire Wire Line
	5450 3850 5450 4050
Wire Wire Line
	5450 4050 5150 4050
Connection ~ 5450 4050
Connection ~ 5150 4050
Wire Wire Line
	5150 3100 5600 3100
Connection ~ 5950 3100
Wire Wire Line
	5550 3650 5150 3650
Connection ~ 5150 3650
Wire Wire Line
	5150 3650 5150 3750
Wire Wire Line
	5950 4300 5950 4700
Wire Wire Line
	6500 3750 6750 3750
Wire Wire Line
	6750 4050 6750 4300
Connection ~ 5950 4700
Wire Wire Line
	4550 4050 4550 4700
Wire Wire Line
	4550 4700 5150 4700
Wire Wire Line
	5150 4650 5150 4700
Connection ~ 5150 4700
Wire Wire Line
	5950 4700 5950 4850
Wire Wire Line
	6750 4600 6750 4850
Wire Wire Line
	6750 4850 5950 4850
Connection ~ 5950 4850
Wire Wire Line
	5950 4850 5950 5100
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 604C9C7C
P 5650 4700
F 0 "#FLG0101" H 5650 4775 50  0001 C CNN
F 1 "PWR_FLAG" H 5650 4873 50  0000 C CNN
F 2 "" H 5650 4700 50  0001 C CNN
F 3 "~" H 5650 4700 50  0001 C CNN
	1    5650 4700
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 604CA17A
P 5600 3100
F 0 "#FLG0102" H 5600 3175 50  0001 C CNN
F 1 "PWR_FLAG" H 5600 3273 50  0000 C CNN
F 2 "" H 5600 3100 50  0001 C CNN
F 3 "~" H 5600 3100 50  0001 C CNN
	1    5600 3100
	1    0    0    -1  
$EndComp
Connection ~ 5600 3100
Wire Wire Line
	5600 3100 5950 3100
Connection ~ 5650 4700
Wire Wire Line
	5650 4700 5950 4700
Wire Wire Line
	5150 4700 5650 4700
NoConn ~ 6150 4300
$EndSCHEMATC
