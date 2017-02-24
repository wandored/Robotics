#pragma config(Sensor, port4,           gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor3,          leftClawMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motor9,          rightClawMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor10,         middleDriveMotor, tmotorVexIQ, PIDControl, encoder)

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

static void resetDirection(void)
{
	resetGyro(gyroSensor);
	clearTimer(T4);
}
static float getDirection(void)
{
	const float drift=0.135;  /*deg/sec gyro drift*/
	return getGyroHeadingFloat(gyroSensor) - drift * time1[T4];
}
static void goForwardGyro(const float deg, const int ms)
{
	const int Fast = 129;
	const int Slow = 80;
	int speedRight = Fast;
	int speedLeft = Fast;
	setMotorSpeed(leftDriveMotor, speedLeft);
	setMotorSpeed(rightDriveMotor, speedRight);
	clearTimer(T1);
	while(time1[T1] < ms)
	{
		float direction = getDirection();
		if (direction > deg) {
			if (speedLeft != Fast) {
				speedLeft = Fast;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
			if (speedRight == Fast) {
				speedRight = Slow;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
		} else if (direction < deg) {
			if (speedLeft == Fast) {
				speedLeft = Slow;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
			if (speedRight != Fast) {
				speedRight = Fast;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
		} else {
			if (speedLeft != Fast) {
				speedLeft = Fast;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
			if (speedRight != Fast) {
				speedRight = Fast;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
		}
	}
}
static void goBackwardGyro(const float deg, const int ms)
{
	const int Fast = -129;
	const int Slow = -80;
	int speedRight = Fast;
	int speedLeft = Fast;
	float direction;
	setMotorSpeed(leftDriveMotor, speedLeft);
	setMotorSpeed(rightDriveMotor, speedRight);
	clearTimer(T1);
	while(time1[T1] < ms)
	{
		direction = getDirection();
		if (direction > deg) {
			if (speedRight != Fast) {
				speedRight = Fast;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
			if (speedLeft == Fast) {
				speedLeft = Slow;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
		} else if (direction < deg) {
			if (speedRight == Fast) {
				speedRight = Slow;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
			if (speedLeft != Fast) {
				speedLeft = Fast;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
		} else {
			if (speedRight != Fast) {
				speedRight = Fast;
				setMotorSpeed(rightDriveMotor, speedRight);
			}
			if (speedLeft != Fast) {
				speedLeft = Fast;
				setMotorSpeed(leftDriveMotor, speedLeft);
			}
		}
	}
}

task main()
{
	middleDrive(800, 100);
	//fourWheelDrive(950, 50);
	resetDirection();
	goForwardGyro(90, 5000);
	goBackwardGyro(270, 2500);

}
