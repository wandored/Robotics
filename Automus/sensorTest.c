#pragma config(Sensor, port2,  colorSensorF,   sensorVexIQ_Color12Color)
#pragma config(Sensor, port3,  colorSensorB,   sensorVexIQ_Color12Color)
#pragma config(Sensor, port4,  distSensorF,    sensorVexIQ_Distance)
#pragma config(Sensor, port9,  distSensorB,    sensorVexIQ_Distance)
#pragma config(Motor,  motor1,          leftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)


static void goForward(const int dist, const int speed)
{
	setMotorSpeed(leftDriveMotor, speed);
	setMotorSpeed(rightDriveMotor, speed);
	waitUntil(getDistanceValue(distSensorB) > dist);
	stopAllMotors();
}

//static void centerBot(const int dist, const int speed);
//{
//	if (getDistanceValue(distSensorF) < dist) {
//			setMotorSpeed(leftDriveMotor, speed);
//			setMotorSpeed(rightDriveMotor, speed);
//			waitUntil(getDistanceValue(distSensorF) = dist);
//				stopAllMotors();
//}
//if (getDistanceValue(distSensorF) > dist) {
//			setMotorSpeed(leftDriveMotor, -(speed));
//			setMotorSpeed(rightDriveMotor, -(speed));
//			waitUntil(getDistanceValue(distSensorF) = dist);
//				stopAllMotors();
//}



task main()
{
//	displaySensorValues(line1, distSensorF);
//	displaySensorValues(line2, distSensorB);
//	setDistanceMaxRange(distSensorF, 1219);
//	setDistanceMaxRange(distSensorB, 1219);
	setDistanceMinRange(distSensorF, 100);
	setDistanceMinRange(distSensorB, 100);
	goForward(610, 75);
//	centerBot(615, 50);
	displaySensorValues(line1, distSensorF);
	displaySensorValues(line2, distSensorB);
  wait(1, minutes);
}


//static float getDirection(void)
//{
//	const float drift=0.135;  /*deg/sec gyro drift*/
//	return getGyroHeadingFloat(gyroSensor) - drift * time1[T4];
//}
//static void goForwardGyro(const float deg, const int ms)
//{
//	const int Fast = 129;
//	const int Slow = 80;
//	int speedRight = Fast;
//	int speedLeft = Fast;
//	setMotorSpeed(leftDriveMotor, speedLeft);
//	setMotorSpeed(rightDriveMotor, speedRight);
//	clearTimer(T1);
//	while(time1[T1] < ms)
//	{
//		float direction = getDirection();
//		if (direction > deg) {
//			if (speedLeft != Fast) {
//				speedLeft = Fast;
//				setMotorSpeed(leftDriveMotor, speedLeft);
//			}
//			if (speedRight == Fast) {
//				speedRight = Slow;
//				setMotorSpeed(rightDriveMotor, speedRight);
//			}
//		} else if (direction < deg) {
//			if (speedLeft == Fast) {
//				speedLeft = Slow;
//				setMotorSpeed(leftDriveMotor, speedLeft);
//			}
//			if (speedRight != Fast) {
//				speedRight = Fast;
//				setMotorSpeed(rightDriveMotor, speedRight);
//			}
//		} else {
//			if (speedLeft != Fast) {
//				speedLeft = Fast;
//				setMotorSpeed(leftDriveMotor, speedLeft);
//			}
//			if (speedRight != Fast) {
//				speedRight = Fast;
//				setMotorSpeed(rightDriveMotor, speedRight);
//			}
//		}
//	}
//}
//static void goBackwardGyro(const float deg, const int ms)
//{
//	const int Fast = -129;
//	const int Slow = -80;
//	int speedRight = Fast;
//	int speedLeft = Fast;
//	float direction;
//	setMotorSpeed(leftDriveMotor, speedLeft);
//	setMotorSpeed(rightDriveMotor, speedRight);
//	clearTimer(T1);
//	while(time1[T1] < ms)
//	{
//		direction = getDirection();
//		if (direction > deg) {
//			if (speedRight != Fast) {
//				speedRight = Fast;
//				setMotorSpeed(rightDriveMotor, speedRight);
//			}
//			if (speedLeft == Fast) {
//				speedLeft = Slow;
//				setMotorSpeed(leftDriveMotor, speedLeft);
//			}
//		} else if (direction < deg) {
//			if (speedRight == Fast) {
//				speedRight = Slow;
//				setMotorSpeed(rightDriveMotor, speedRight);
//			}
//			if (speedLeft != Fast) {
//				speedLeft = Fast;
//				setMotorSpeed(leftDriveMotor, speedLeft);
//			}
//		} else {
//			if (speedRight != Fast) {
//				speedRight = Fast;
//				setMotorSpeed(rightDriveMotor, speedRight);
//			}
//			if (speedLeft != Fast) {
//				speedLeft = Fast;
//				setMotorSpeed(leftDriveMotor, speedLeft);
//			}
//		}
//	}
//}

//task main()
//{
//	middleDrive(800, 100);
//	//fourWheelDrive(950, 50);
//	resetDirection();
//	goForwardGyro(90, 5000);
//	goBackwardGyro(270, 2500);

//}
