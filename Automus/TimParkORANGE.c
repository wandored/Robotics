#pragma config(Sensor, port4,           gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor3,          leftClawMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor9,          rightClawMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor10,         middleDriveMotor, tmotorVexIQ, PIDControl, encoder)

// Park on the bridge from the Orange Scoring Zone starting position.

task main()
{
	//reset all motors & sensors
	resetMotorEncoder(leftDriveMotor);
	resetMotorEncoder(rightDriveMotor);
	resetGyro(gyroSensor);

  //move to the middle of the field
	moveMotorTarget(middleDriveMotor, -770, 100);
	waitUntilMotorStop(middleDriveMotor);

  //Drive backward up the ramp and balance it
	moveMotorTarget(leftDriveMotor, -1300, 100);
	moveMotorTarget(rightDriveMotor, -1300, 100);
	waitUntilMotorStop(leftDriveMotor);

	//Hold position
	setMotorBrakeMode(leftDriveMotor, motorBrake);
	setMotorBrakeMode(rightDriveMotor, motorBrake);
}
