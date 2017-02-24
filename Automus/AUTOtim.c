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

static void middleDrive(const int ecount, const int speed)
{
	moveMotorTarget(middleDriveMotor, ecount, speed);
	waitUntilMotorStop(middleDriveMotor);
}

static void moveClaw(const int ecount, const int speed)
{
	moveMotorTarget(leftClawMotor, ecount, speed);
	moveMotorTarget(rightClawMotor, ecount, speed);
	waitUntilMotorStop(leftClawMotor);
}

static void fourWheelDrive(const int ecount, const int speed)
{
	moveMotorTarget(leftDriveMotor, ecount, speed);
	moveMotorTarget(rightDriveMotor, ecount, speed);
	waitUntilMotorStop(leftDriveMotor);
}

task main()
{
	resetDirection();
	middleDrive(1488, 100);
	moveClaw(180, 75);
	fourWheelDrive(950, 50);
	moveClaw(-270, 75);
	fourWheelDrive(-950, 75);
	middleDrive(770, 75);
	fourWheelDrive(-480, 50);
	moveClaw(-200, 100);
	wait(1, seconds);
	moveClaw(150, 100);
}


//	//lift claws to remove balls from rail
//	moveMotorTarget(leftClawMotor, -270, 75);
//	moveMotorTarget(rightClawMotor, -270, 75);
//	waitUntilMotorMoveComplete(leftClawMotor);
//	stopAllMotors();

//	//Reverse robot back to position
//	moveMotorTarget(leftDriveMotor, -950, 75);
//	moveMotorTarget(rightDriveMotor, -950, 75);
//	waitUntilMotorStop(leftDriveMotor);

//	//move robot to cemnter of perimeter in front of scoring zone
//		moveMotorTarget(middleDriveMotor, 770, 75);
//	waitUntilMotorStop(middleDriveMotor);
//	displayMotorValues(line3, leftDriveMotor);

//	//Move robot toward scoring zone to deposit balls
//	moveMotorTarget(leftDriveMotor, -480, 50);
//	moveMotorTarget(rightDriveMotor, -480, 50);
//	waitUntilMotorStop(leftDriveMotor);

//	//lower claws to deposit balls
//	moveMotorTarget(leftClawMotor, -200, 100);
//	moveMotorTarget(rightClawMotor, -200, 100);
//	waitUntilMotorMoveComplete(leftClawMotor);
//	//stopAllMotors();
//	wait(1, seconds);

//	moveMotorTarget(leftClawMotor, 150, 75);
//	moveMotorTarget(rightClawMotor, 150, 75);
//	waitUntilMotorMoveComplete(leftClawMotor);
//	stopAllMotors();



//	stopAllMotors();
//}
