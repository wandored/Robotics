#pragma config(Sensor, port2,  colorSensorF,   sensorVexIQ_Color12Color)
#pragma config(Sensor, port3,  colorSensorB,   sensorVexIQ_Color12Color)
#pragma config(Sensor, port4,  distSensorF,    sensorVexIQ_Distance)
#pragma config(Sensor, port9,  distSensorB,    sensorVexIQ_Distance)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	repeat (forever) {
		displaySensorValues(line1, distSensorF);
		displaySensorValues(line2, distSensorB);
		displaySensorValues(line4, colorSensorF);
		displaySensorValues(line5, colorSensorB);

		tankControl(ChD, ChA, 2);

		}
}