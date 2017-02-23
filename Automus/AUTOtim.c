#pragma config(Sensor, port4,           gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor3,          leftClawMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor9,          rightClawMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor10,         middleDriveMotor, tmotorVexIQ, PIDControl, encoder)


static void resetDirection(void)
	{
		resetGyro(gyroSensor);
	}

task main()
{
	resetGyro(gyroSensor);

	// Move across the filed and stop 5 inches from the wall
	moveMotorTarget(middleDriveMotor, -1488, 100); // Move to rail and knock balls off
	waitUntilMotorStop(middleDriveMotor);
	//test
	displayMotorValues(line3, leftDriveMotor);

	//Raise the claw into position
	moveMotorTarget(leftClawMotor, -180, 100);
	moveMotorTarget(rightClawMotor, -180, 100);
	waitUntilMotorMoveComplete(leftClawMotor);

	//Move robot towards rail to pick up balls
	setMultipleMotors(50, leftDriveMotor, rightDriveMotor);
	waitUntil(getMotorEncoder(leftDriveMotor) > 950);
	stopAllMotors();

	//lift claws to remove balls from rail
	moveMotorTarget(leftClawMotor, -270, 75);
	moveMotorTarget(rightClawMotor, -270, 75);
	waitUntilMotorMoveComplete(leftClawMotor);
	stopAllMotors();

	//Reverse robot back to position
	moveMotorTarget(leftDriveMotor, -950, 75);
	moveMotorTarget(rightDriveMotor, -950, 75);
	waitUntilMotorStop(leftDriveMotor);

	//move robot to cemnter of perimeter in front of scoring zone
		moveMotorTarget(middleDriveMotor, 770, 75);
	waitUntilMotorStop(middleDriveMotor);
	displayMotorValues(line3, leftDriveMotor);

	//Move robot toward scoring zone to deposit balls
	moveMotorTarget(leftDriveMotor, -480, 50);
	moveMotorTarget(rightDriveMotor, -480, 50);
	waitUntilMotorStop(leftDriveMotor);

	//lower claws to deposit balls
	moveMotorTarget(leftClawMotor, -200, 100);
	moveMotorTarget(rightClawMotor, -200, 100);
	waitUntilMotorMoveComplete(leftClawMotor);
	//stopAllMotors();
	wait(1, seconds);

	moveMotorTarget(leftClawMotor, 150, 75);
	moveMotorTarget(rightClawMotor, 150, 75);
	waitUntilMotorMoveComplete(leftClawMotor);
	stopAllMotors();



	stopAllMotors();
}
