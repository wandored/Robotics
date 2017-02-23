
#pragma config(Sensor, port4,           gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor3,          leftClawMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor9,          rightClawMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor10,         middleDriveMotor, tmotorVexIQ, PIDControl, encoder)


task main()
{
	resetGyro(gyroSensor);

	//Raise the claw into position
	moveMotorTarget(leftClawMotor, -160, 100);
	moveMotorTarget(rightClawMotor, -160, 100);
	waitUntilMotorMoveComplete(leftClawMotor);

	//Move robot towards rail to pick up balls
	setMultipleMotors(50, leftDriveMotor, rightDriveMotor);
	waitUntil(getMotorEncoder(leftDriveMotor) > 950);
	stopAllMotors();

	//lift claws to remove balls from rail
	moveMotorTarget(leftClawMotor, -300, 75);
	moveMotorTarget(rightClawMotor, -300, 75);
	waitUntilMotorMoveComplete(leftClawMotor);
	stopAllMotors();

	//Reverse robot back to position
	moveMotorTarget(leftDriveMotor, -950, 750);
	moveMotorTarget(rightDriveMotor, -950, 750);
	waitUntilMotorStop(leftDriveMotor);

	//move robot to cemnter of perimeter in front of scoring zone
		moveMotorTarget(middleDriveMotor, 770, 75);
	waitUntilMotorStop(middleDriveMotor);
	displayMotorValues(line3, leftDriveMotor);

	//Move robot toward scoring zone to deposit balls
	moveMotorTarget(leftDriveMotor, -550, 50);
	moveMotorTarget(rightDriveMotor, -550, 50);
	waitUntilMotorStop(leftDriveMotor);

	//lower claws to deposit balls
	moveMotorTarget(leftClawMotor, -150, -75);
	moveMotorTarget(rightClawMotor, -150, -75);
	waitUntilMotorMoveComplete(leftClawMotor);
	stopAllMotors();

	//"Shimmy Shammy" or go left & right quickly to deposit any balls that were stuck
	moveMotorTarget(leftDriveMotor, 50, 100);
	waitUntilMotorMoveComplete(leftDriveMotor);
	moveMotorTarget(rightDriveMotor, 50, 100);
	waitUntilMotorMoveComplete(rightDriveMotor);
	moveMotorTarget(leftDriveMotor, 50, 100);
	waitUntilMotorMoveComplete(leftDriveMotor);
	moveMotorTarget(rightDriveMotor, 50, 100);
	waitUntilMotorMoveComplete(rightDriveMotor);
	moveMotorTarget(leftDriveMotor, 50, 100);
	waitUntilMotorMoveComplete(leftDriveMotor);
	moveMotorTarget(rightDriveMotor, 50, 100);
	waitUntilMotorMoveComplete(rightDriveMotor);
	moveMotorTarget(leftDriveMotor, 50, 100);
	waitUntilMotorMoveComplete(leftDriveMotor);
	moveMotorTarget(rightDriveMotor, 50, 100);
	waitUntilMotorMoveComplete(rightDriveMotor);

	stopAllMotors();
}
