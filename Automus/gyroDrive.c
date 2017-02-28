#pragma config(Sensor, port4,           gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor3,          leftClawMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor9,          rightClawMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor10,         middleDriveMotor, tmotorVexIQ, PIDControl, encoder)
/************************************************************************************************************/

static float getDirection(void)
{
	const float drift=0.135;  /*deg/sec gyro drift*/
	return getGyroHeadingFloat(gyroSensor) - drift * time1[T4];
}

static void middleDrive(const int ecount, const int speed, const float deg)
{
//	const int Fast = 50;
	const int slow = (speed - 25);
	int speedRight = speed;
	int speedLeft = speed;
	setMotorSpeed(leftDriveMotor, speedLeft);
	setMotorSpeed(rightDriveMotor, speedRight);
	while(getMotorEncoder(leftDriveMotor) < ecount)
	{
		float direction = getDirection();
		if (direction > deg) {
			if (speedLeft != speed) {
				speedLeft = speed;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
			if (speedRight == speed) {
				speedRight = slow;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
		} else if (direction < deg) {
			if (speedLeft == speed) {
				speedLeft = slow;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
			if (speedRight != speed) {
				speedRight = speed;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
		} else {
			if (speedLeft != speed) {
				speedLeft = speed;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
			if (speedRight != speed) {
				speedRight = speed;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
		}
	}
	stopAllMotors();
}
//*************************************************************
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
	resetGyro(gyroSensor);
	middleDrive(1488, 50, 0.0);
	//moveClaw(180, 75);
	//fourWheelDrive(950, 50);
	//moveClaw(-270, 75);
	//fourWheelDrive(-950, 75);
	//middleDrive(770, 75);
	//fourWheelDrive(-480, 50);
	//moveClaw(-200, 100);
	//wait(1, seconds);
	//moveClaw(150, 100);
	stopAllMotors();
}
